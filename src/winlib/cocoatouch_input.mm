#import "cocoatouch_input.h"
#include "ghl_event.h"
#include "ghl_application.h"
#include "ghl_system.h"

@implementation IndexedPosition
@synthesize index = _index;

+ (IndexedPosition *)positionWithIndex:(NSUInteger)index {
    IndexedPosition *pos = [[IndexedPosition alloc] init];
    pos.index = index;
    return [pos autorelease];
}

@end

@implementation IndexedRange
@synthesize range = _range;

+ (IndexedRange *)rangeWithNSRange:(NSRange)nsrange {
    if (nsrange.location == NSNotFound)
        return nil;
    assert(NSInteger(nsrange.length)>=0);
    IndexedRange *range = [[IndexedRange alloc] init];
    range.range = nsrange;
    return [range autorelease];
}

- (UITextPosition *)start {
    return [IndexedPosition positionWithIndex:self.range.location];
}

- (UITextPosition *)end {
    return [IndexedPosition positionWithIndex:(self.range.location + self.range.length)];
}

-(BOOL)isEmpty {
    return (self.range.length == 0);
}
@end



@implementation HiddenInput

-(id)initWithApplication:(GHL::Application*) app {
    if (self = [super init]) {
        m_app = app;
        m_data = nil;
        m_tokenizer = [[UITextInputStringTokenizer alloc] initWithTextInput:self];
    }
    return self;
}

- (id<UITextInputTokenizer>) tokenizer {
    return m_tokenizer;
}

- (UITextRange*) markedTextRange {
    return [IndexedRange rangeWithNSRange:m_marked_range];
}

- (UITextRange*) selectedTextRange {
    return [IndexedRange rangeWithNSRange:m_selected_range];
}
- (void) setSelectedTextRange:(UITextRange *)range {
    IndexedRange *r = (IndexedRange *)range;
    m_selected_range = r.range;
    //m_selected_range.length = 0;
    //NSLog(@"set m_selected_range: %@",NSStringFromRange(m_selected_range));
}

- (UITextPosition*) beginningOfDocument {
    return [IndexedPosition positionWithIndex:0];
}

- (UITextPosition*) endOfDocument {
    if (m_data) {
        [IndexedPosition positionWithIndex:[m_data length]];
    }
    return [self beginningOfDocument];
}

-(void)dealloc {
    [m_tokenizer release];
    [m_data release];
    [super dealloc];
}

- (void)setInputDelegate:(id<UITextInputDelegate>) delegate {
    m_delegate = delegate;
}
- (id<UITextInputDelegate>) inputDelegate {
    return m_delegate;
}

/// KeyInput
- (void)insertText:(NSString *)text {
    if (!text) return;
    if (text.length < 1)
        return;
    if (m_data) {
        [m_data insertString:text atIndex:m_selected_range.location+m_selected_range.length];
        m_selected_range.location += text.length;
    }
    if (m_data && text && [text characterAtIndex:0]!='\n') {
        [self sendText];
    } else {
        int len = text.length;
        int idx = 0;
        while (idx < len) {
            unichar chars[2];
            [text getCharacters:chars range:NSMakeRange(idx, 1)];
            ++idx;
            UInt32 wc = chars[0];
            if (CFStringIsSurrogateHighCharacter(chars[0]) && idx<len) {
                [text getCharacters:&chars[1] range:NSMakeRange(idx, 1)];
                ++idx;
                wc = CFStringGetLongCharacterForSurrogatePair(chars[0],chars[1]);
            }
            GHL::Event e;
            e.type = GHL::EVENT_TYPE_KEY_PRESS;
            e.data.key_press.key = wc == '\n' ? GHL::KEY_ENTER : GHL::KEY_NONE;
            e.data.key_press.modificators = 0;
            e.data.key_press.charcode = wc;
            m_app->OnEvent(&e);
            e.type = GHL::EVENT_TYPE_KEY_RELEASE;
            e.data.key_release.key = e.data.key_press.key;
            m_app->OnEvent(&e);
        }
    }
}
- (void)deleteBackward {
    if (m_data) {
        if (m_selected_range.length) {
            [m_data deleteCharactersInRange:m_selected_range];
            m_selected_range.length = 0;
//            NSLog(@"deleteBackward selectedRange");
        } else if (m_data.length > 0) {
            [m_data deleteCharactersInRange:NSMakeRange(m_data.length-1, 1)];
            m_selected_range.location -= 1;
        }
        
//        NSLog(@"m_marked_range: %@",NSStringFromRange(m_marked_range));
//        NSLog(@"m_selected_range: %@",NSStringFromRange(m_selected_range));
//        NSLog(@"m_data: %@",m_data);
//
        [self sendText];
    } else {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_KEY_PRESS;
        e.data.key_press.key = GHL::KEY_BACKSPACE;
        e.data.key_press.modificators = 0;
        e.data.key_press.charcode = 0;
        m_app->OnEvent(&e);
        e.type = GHL::EVENT_TYPE_KEY_RELEASE;
        e.data.key_release.key = e.data.key_press.key;
        m_app->OnEvent(&e);
    }
}
- (BOOL)hasText {
    // Return whether there's any text present
    return YES;
}
- (BOOL)canBecomeFirstResponder {
    return YES;
}

- (NSUInteger) utf32position:(NSUInteger) index {
    NSUInteger idx = 0;
    NSUInteger i =0;
    while (idx<index) {
        unichar ch = [m_data characterAtIndex:idx];
        if (CFStringIsSurrogateHighCharacter(ch)) {
            idx += 2;
        } else {
            idx += 1;
        }
        ++i;
    }
    return i;
}

- (NSUInteger) utf16position:(NSUInteger) index {
    NSUInteger idx = 0;
    NSUInteger i =0;
    while (i<index) {
        unichar ch = [m_data characterAtIndex:idx];
        if (CFStringIsSurrogateHighCharacter(ch)) {
            idx += 2;
        } else {
            idx += 1;
        }
        ++i;
    }
    return idx;
}

///
- (void)sendText {
    if (m_data) {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_TEXT_INPUT_TEXT_CHANGED;
        e.data.text_input_text_changed.text = [m_data UTF8String];
        e.data.text_input_text_changed.cursor_position = [self utf32position:m_selected_range.location];
        if (e.data.text_input_text_changed.text) {
            m_app->OnEvent(&e);
        }
    }
}
/// text input
- (nullable NSString *)textInRange:(UITextRange *)range {
    if (!m_data) {
        return nil;
    }
    if (!range) {
        return nil;
    }
    NSRange subrange = NSIntersectionRange(NSMakeRange(0, m_data.length), ((IndexedRange*)range).range);
    if (subrange.location == NSNotFound)
        return nil;
    NSString* res = [m_data substringWithRange:subrange];
    return res;
}

- (void)replaceRange:(UITextRange *)range withText:(NSString *)text {
    if (m_data) {
        IndexedRange *r = (IndexedRange *)range;
        if ((r.range.location + r.range.length) <= m_selected_range.location) {
            m_selected_range.location -= (r.range.length - text.length);
        } else {
            // Need to also deal with overlapping ranges.
        }
        [m_data replaceCharactersInRange:r.range withString:text];
    }
}

- (void)setMarkedText:(NSString *)markedText selectedRange:(NSRange)selectedRange {
    NSRange selectedNSRange = m_selected_range;
    NSRange markedTextRange = m_marked_range;
    //NSLog(@"setMarkedText: %@",markedText);
    
    if (markedTextRange.location != NSNotFound) {
        if (!markedText)
            markedText = @"";
        [m_data replaceCharactersInRange:markedTextRange withString:markedText];
        markedTextRange.length = markedText.length;
        
    } else if (selectedNSRange.length > 0) {
        [m_data replaceCharactersInRange:selectedNSRange withString:markedText];
        markedTextRange.location = selectedNSRange.location;
        markedTextRange.length = markedText.length;
    } else {
        [m_data insertString:markedText atIndex:selectedNSRange.location];
        markedTextRange.location = selectedNSRange.location;
        markedTextRange.length = markedText.length;
    }
    selectedNSRange = NSMakeRange(selectedRange.location + markedTextRange.location,
                                  selectedRange.length);
    if (markedTextRange.length == 0) {
        markedTextRange.location = NSNotFound;
    }
    m_marked_range = markedTextRange;
    m_selected_range = selectedNSRange;
//    NSLog(@"m_marked_range: %@",NSStringFromRange(m_marked_range));
//    NSLog(@"m_selected_range: %@",NSStringFromRange(m_selected_range));
//    NSLog(@"m_data: %@",m_data);
    [self sendText];
}

- (void)unmarkText {
    m_marked_range.location = NSNotFound;
    m_marked_range.length = 0;
}

/* The end and beginning of the the text document. */

/* Methods for creating ranges and positions. */
- (nullable UITextRange *)textRangeFromPosition:(UITextPosition *)fromPosition toPosition:(UITextPosition *)toPosition {
    IndexedPosition *from = (IndexedPosition *)fromPosition;
    IndexedPosition *to = (IndexedPosition *)toPosition;
    NSRange range = NSMakeRange(MIN(from.index, to.index), ABS(NSInteger(to.index) - NSInteger(from.index)));
    return [IndexedRange rangeWithNSRange:range];
}
- (nullable UITextPosition *)positionFromPosition:(UITextPosition *)position offset:(NSInteger)offset {
    IndexedPosition *pos = (IndexedPosition *)position;
    NSInteger end = pos.index + offset;
    if (end > m_data.length || end < 0)
        return nil;
    return [IndexedPosition positionWithIndex:end];
}
- (nullable UITextPosition *)positionFromPosition:(UITextPosition *)position inDirection:(UITextLayoutDirection)direction offset:(NSInteger)offset {
    return [self positionFromPosition:position offset:offset];
}

/* Simple evaluation of positions */
- (NSComparisonResult)comparePosition:(UITextPosition *)position toPosition:(UITextPosition *)other {
    int a = [(IndexedPosition *)position index];
    int b = [(IndexedPosition *)other index];
    
    if ( a < b ) return NSOrderedAscending;
    else if ( a > b ) return NSOrderedDescending;
    return NSOrderedSame;
}
- (NSInteger)offsetFromPosition:(UITextPosition *)from toPosition:(UITextPosition *)toPosition {
    IndexedPosition *f = (IndexedPosition *)from;
    IndexedPosition *t = (IndexedPosition *)toPosition;
    return (t.index - f.index);
}

- (nullable UITextPosition *)positionWithinRange:(UITextRange *)range farthestInDirection:(UITextLayoutDirection)direction {
    return nil;
}
- (nullable UITextRange *)characterRangeByExtendingPosition:(UITextPosition *)position inDirection:(UITextLayoutDirection)direction {
    return nil;
}

/* Writing direction */
- (UITextWritingDirection)baseWritingDirectionForPosition:(UITextPosition *)position inDirection:(UITextStorageDirection)direction {
    return UITextWritingDirectionNatural;
}
- (void)setBaseWritingDirection:(UITextWritingDirection)writingDirection forRange:(UITextRange *)range {
    
}

/* Geometry used to provide, for example, a correction rect. */
- (CGRect)firstRectForRange:(UITextRange *)range {
    return CGRectZero;
}
- (CGRect)caretRectForPosition:(UITextPosition *)position {
    return CGRectZero;
}
- (NSArray *)selectionRectsForRange:(UITextRange *)range {
    return nil;
}

/* Hit testing. */
- (nullable UITextPosition *)closestPositionToPoint:(CGPoint)point {
    return nil;
}
- (nullable UITextPosition *)closestPositionToPoint:(CGPoint)point withinRange:(UITextRange *)range {
    return nil;
}
- (nullable UITextRange *)characterRangeAtPoint:(CGPoint)point {
    return nil;
}


-(void)showWithConfig:(const GHL::TextInputConfig*) config {
    if (m_data) {
        [m_data release];
        m_data = nil;
    }
    if (config->text) {
        if (m_delegate) {
            [m_delegate selectionWillChange:self];
            [m_delegate textWillChange:self];
        }
        m_data = [[NSMutableString alloc] init];
        [m_data setString:[NSString stringWithUTF8String:config->text]];
        
        if (![self isFirstResponder]) {
            m_marked_range = NSMakeRange(NSNotFound, 0);
        }
        if (m_marked_range.location != NSNotFound) {
            if (m_marked_range.location > m_data.length) {
                m_marked_range.location = NSNotFound;
            } else {
                if (m_marked_range.location + m_marked_range.length > m_data.length) {
                    m_marked_range.length = m_data.length - m_marked_range.location;
                }
            }
        }
        m_selected_range = NSMakeRange([self utf16position:config->cursor_position], 0);
        if (m_selected_range.location > m_data.length) {
            m_selected_range.location = m_data.length;
        }
        if (m_delegate) {
            [m_delegate selectionDidChange:self];
            [m_delegate textDidChange:self];
        }
        
//        NSLog(@"showWithConfig");
//        NSLog(@"m_marked_range: %@",NSStringFromRange(m_marked_range));
//        NSLog(@"m_selected_range: %@",NSStringFromRange(m_selected_range));
//        NSLog(@"m_data: %@",m_data);
    }
    [self becomeFirstResponder];
}
-(void)show {
    if (m_data) {
        [m_data release];
        m_data = nil;
    }
    self.autocorrectionType = UITextAutocorrectionTypeNo;
    [self becomeFirstResponder];
}
@end

