#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
namespace GHL {
    struct Application;
    struct TextInputConfig;
}

@interface IndexedPosition : UITextPosition {
    NSUInteger _index;
    id <UITextInputDelegate> _inputDelegate;
}
@property (nonatomic) NSUInteger index;
+ (IndexedPosition *)positionWithIndex:(NSUInteger)index;
@end



@interface IndexedRange : UITextRange {
    NSRange _range;
}
@property (nonatomic) NSRange range;
+ (IndexedRange *)rangeWithNSRange:(NSRange)range;

@end

@interface HiddenInput : UIView <UITextInput> {
    GHL::Application*    m_app;
    NSMutableString* m_data;
    NSRange m_marked_range;
    NSRange m_selected_range;
    id<UITextInputDelegate> m_delegate;
    UITextInputStringTokenizer* m_tokenizer;
}

@property(nonatomic) UITextAutocapitalizationType autocapitalizationType; // default is UITextAutocapitalizationTypeSentences
@property(nonatomic) UITextAutocorrectionType autocorrectionType;         // default is UITextAutocorrectionTypeDefault
@property(nonatomic) UITextSpellCheckingType spellCheckingType;  // default is UITextSpellCheckingTypeDefault;
@property(nonatomic) UIKeyboardType keyboardType;                         // default is UIKeyboardTypeDefault
@property(nonatomic) UIKeyboardAppearance keyboardAppearance;             // default is UIKeyboardAppearanceDefault
@property(nonatomic) UIReturnKeyType returnKeyType;                       // default is

//@property (nullable, readwrite, copy) UITextRange *selectedTextRange;
//@property (nullable, nonatomic, readonly) UITextRange *markedTextRange; // Nil if no marked text.
@property (nullable, nonatomic, copy) NSDictionary *markedTextStyle; // Describes how the marked text should be drawn.

//@property (nonatomic, readonly) UITextPosition *beginningOfDocument;
//@property (nonatomic, readonly) UITextPosition *endOfDocument;

-(id)initWithApplication:(GHL::Application*) app;
-(void)showWithConfig:(const GHL::TextInputConfig*) config;
-(void)show;
@end

