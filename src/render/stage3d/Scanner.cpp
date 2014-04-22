

#include <memory.h>
#include <string.h>
#include "Scanner.h"

namespace GHL {
namespace AGAL {



// string handling, wide character


char* coco_string_create(const char* value) {
	return coco_string_create(value, 0);
}

char* coco_string_create(const char *value, int startIndex) {
	int valueLen = 0;
	int len = 0;

	if (value) {
		valueLen = strlen(value);
		len = valueLen - startIndex;
	}

	return coco_string_create(value, startIndex, len);
}

char* coco_string_create(const char *value, int startIndex, int length) {
	int len = 0;
	char* data;

	if (value) { len = length; }
	data = new char[len + 1];
	strncpy(data, &(value[startIndex]), len);
	data[len] = 0;

	return data;
}

char* coco_string_create_upper(const char* data) {
	if (!data) { return NULL; }

	int dataLen = 0;
	if (data) { dataLen = strlen(data); }

	char *newData = new char[dataLen + 1];

	for (int i = 0; i <= dataLen; i++) {
		if ((L'a' <= data[i]) && (data[i] <= L'z')) {
			newData[i] = data[i] + (L'A' - L'a');
		}
		else { newData[i] = data[i]; }
	}

	newData[dataLen] = L'\0';
	return newData;
}

char* coco_string_create_lower(const char* data) {
	if (!data) { return NULL; }
	int dataLen = strlen(data);
	return coco_string_create_lower(data, 0, dataLen);
}

char* coco_string_create_lower(const char* data, int startIndex, int dataLen) {
	if (!data) { return NULL; }

	char* newData = new char[dataLen + 1];

	for (int i = 0; i <= dataLen; i++) {
		char ch = data[startIndex + i];
		if ((L'A' <= ch) && (ch <= L'Z')) {
			newData[i] = ch - (L'A' - L'a');
		}
		else { newData[i] = ch; }
	}
	newData[dataLen] = L'\0';
	return newData;
}

char* coco_string_create_append(const char* data1, const char* data2) {
	char* data;
	int data1Len = 0;
	int data2Len = 0;

	if (data1) { data1Len = strlen(data1); }
	if (data2) {data2Len = strlen(data2); }

	data = new char[data1Len + data2Len + 1];

	if (data1) { strcpy(data, data1); }
	if (data2) { strcpy(data + data1Len, data2); }

	data[data1Len + data2Len] = 0;

	return data;
}

char* coco_string_create_append(const char *target, const char appendix) {
	int targetLen = coco_string_length(target);
	char* data = new char[targetLen + 2];
	strncpy(data, target, targetLen);
	data[targetLen] = appendix;
	data[targetLen + 1] = 0;
	return data;
}

void coco_string_delete(char* &data) {
	delete [] data;
	data = NULL;
}

int coco_string_length(const char* data) {
	if (data) { return strlen(data); }
	return 0;
}

bool coco_string_endswith(const char* data, const char *end) {
	int dataLen = strlen(data);
	int endLen = strlen(end);
	return (endLen <= dataLen) && (strcmp(data + dataLen - endLen, end) == 0);
}

int coco_string_indexof(const char* data, const char value) {
	const char* chr = strchr(data, value);

	if (chr) { return (chr-data); }
	return -1;
}

int coco_string_lastindexof(const char* data, const char value) {
	const char* chr = strrchr(data, value);

	if (chr) { return (chr-data); }
	return -1;
}

void coco_string_merge(char* &target, const char* appendix) {
	if (!appendix) { return; }
	char* data = coco_string_create_append(target, appendix);
	delete [] target;
	target = data;
}

bool coco_string_equal(const char* data1, const char* data2) {
	return strcmp( data1, data2 ) == 0;
}

int coco_string_compareto(const char* data1, const char* data2) {
	return strcmp(data1, data2);
}

int coco_string_hash(const char *data) {
	int h = 0;
	if (!data) { return 0; }
	while (*data != 0) {
		h = (h * 7) ^ *data;
		++data;
	}
	if (h < 0) { h = -h; }
	return h;
}



Token::Token() {
	kind = 0;
	pos  = 0;
	col  = 0;
	line = 0;
	val  = NULL;
	next = NULL;
}

Token::~Token() {
	coco_string_delete(val);
}



Buffer::Buffer(Buffer *b) {
	buf = b->buf;
	bufCapacity = b->bufCapacity;
	b->buf = NULL;
	bufStart = b->bufStart;
	bufLen = b->bufLen;
	fileLen = b->fileLen;
	bufPos = b->bufPos;
}

Buffer::Buffer(const unsigned char* buf, int len) {
	this->buf = new unsigned char[len];
	memcpy(this->buf, buf, len*sizeof(unsigned char));
	bufStart = 0;
	bufCapacity = bufLen = len;
	fileLen = len;
	bufPos = 0;
}

Buffer::~Buffer() {
	if (buf != NULL) {
		delete [] buf;
		buf = NULL;
	}
}


int Buffer::Read() {
	if (bufPos < bufLen) {
		return buf[bufPos++];
	} else if (GetPos() < fileLen) {
		SetPos(GetPos()); // shift buffer start to Pos
		return buf[bufPos++];
	} else {
		return EoF;
	}
}

int Buffer::Peek() {
	int curPos = GetPos();
	int ch = Read();
	SetPos(curPos);
	return ch;
}

// beg .. begin, zero-based, inclusive, in byte
// end .. end, zero-based, exclusive, in byte
char* Buffer::GetString(int beg, int end) {
	int len = 0;
	char *buf = new char[end - beg];
	int oldPos = GetPos();
	SetPos(beg);
	while (GetPos() < end) buf[len++] = (char) Read();
	SetPos(oldPos);
	char *res = coco_string_create(buf, 0, len);
	coco_string_delete(buf);
	return res;
}

int Buffer::GetPos() {
	return bufPos + bufStart;
}

void Buffer::SetPos(int value) {
	
	if ((value < 0) || (value > fileLen)) {
		printf("--- buffer out of bounds access, position: %d\n", value);
		exit(1);
	}

	if ((value >= bufStart) && (value < (bufStart + bufLen))) { // already in buffer
		bufPos = value - bufStart;
	} else {
		bufPos = fileLen - bufStart; // make Pos return fileLen
	}
}

int UTF8Buffer::Read() {
	int ch;
	do {
		ch = Buffer::Read();
		// until we find a utf8 start (0xxxxxxx or 11xxxxxx)
	} while ((ch >= 128) && ((ch & 0xC0) != 0xC0) && (ch != EoF));
	if (ch < 128 || ch == EoF) {
		// nothing to do, first 127 chars are the same in ascii and utf8
		// 0xxxxxxx or end of file character
	} else if ((ch & 0xF0) == 0xF0) {
		// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
		int c1 = ch & 0x07; ch = Buffer::Read();
		int c2 = ch & 0x3F; ch = Buffer::Read();
		int c3 = ch & 0x3F; ch = Buffer::Read();
		int c4 = ch & 0x3F;
		ch = (((((c1 << 6) | c2) << 6) | c3) << 6) | c4;
	} else if ((ch & 0xE0) == 0xE0) {
		// 1110xxxx 10xxxxxx 10xxxxxx
		int c1 = ch & 0x0F; ch = Buffer::Read();
		int c2 = ch & 0x3F; ch = Buffer::Read();
		int c3 = ch & 0x3F;
		ch = (((c1 << 6) | c2) << 6) | c3;
	} else if ((ch & 0xC0) == 0xC0) {
		// 110xxxxx 10xxxxxx
		int c1 = ch & 0x1F; ch = Buffer::Read();
		int c2 = ch & 0x3F;
		ch = (c1 << 6) | c2;
	}
	return ch;
}

Scanner::Scanner(const unsigned char* buf, int len) {
	buffer = new Buffer(buf, len);
	Init();
}

Scanner::~Scanner() {
	char* cur = (char*) firstHeap;

	while(cur != NULL) {
		cur = *(char**) (cur + COCO_HEAP_BLOCK_SIZE);
		free(firstHeap);
		firstHeap = cur;
	}
	delete [] tval;
	delete buffer;
}

void Scanner::Init() {
	EOL    = '\n';
	eofSym = 0;
	maxT = 24;
	noSym = 24;
	int i;
	for (i = 49; i <= 49; ++i) start.set(i, 59);
	for (i = 51; i <= 57; ++i) start.set(i, 59);
	for (i = 65; i <= 90; ++i) start.set(i, 14);
	for (i = 97; i <= 122; ++i) start.set(i, 14);
	start.set(48, 60);
	start.set(10, 13);
	start.set(13, 12);
	start.set(35, 61);
	start.set(50, 62);
	start.set(61, 64);
	start.set(123, 65);
	start.set(59, 66);
	start.set(125, 67);
	start.set(44, 68);
	start.set(60, 69);
	start.set(62, 70);
	start.set(46, 71);
		start.set(Buffer::EoF, -1);
	keywords.set(COCOTEXT("linear"), 12);
	keywords.set(COCOTEXT("mipdisable"), 13);
	keywords.set(COCOTEXT("repeat"), 14);


	tvalLength = 128;
	tval = new char[tvalLength]; // text of current token

	// COCO_HEAP_BLOCK_SIZE byte heap + pointer to next heap block
	heap = malloc(COCO_HEAP_BLOCK_SIZE + sizeof(void*));
	firstHeap = heap;
	heapEnd = (void**) (((char*) heap) + COCO_HEAP_BLOCK_SIZE);
	*heapEnd = 0;
	heapTop = heap;
	if (sizeof(Token) > COCO_HEAP_BLOCK_SIZE) {
		printf("--- Too small COCO_HEAP_BLOCK_SIZE\n");
		exit(1);
	}

	pos = -1; line = 1; col = 0; charPos = -1;
	oldEols = 0;
	NextCh();
	if (ch == 0xEF) { // check optional byte order mark for UTF-8
		NextCh(); int ch1 = ch;
		NextCh(); int ch2 = ch;
		if (ch1 != 0xBB || ch2 != 0xBF) {
			printf("Illegal byte order mark at start of file");
			exit(1);
		}
		Buffer *oldBuf = buffer;
		buffer = new UTF8Buffer(buffer); col = 0; charPos = -1;
		delete oldBuf; oldBuf = NULL;
		NextCh();
	}


	pt = tokens = CreateToken(); // first token is a dummy
}

void Scanner::NextCh() {
	if (oldEols > 0) { ch = EOL; oldEols--; }
	else {
		pos = buffer->GetPos();
		// buffer reads unicode chars, if UTF8 has been detected
		ch = buffer->Read(); col++; charPos++;
		// replace isolated '\r' by '\n' in order to make
		// eol handling uniform across Windows, Unix and Mac
		if (ch == L'\r' && buffer->Peek() != L'\n') ch = EOL;
		if (ch == EOL) { line++; col = 0; }
	}

}

void Scanner::AddCh() {
	if (tlen >= tvalLength) {
		tvalLength *= 2;
		char *newBuf = new char[tvalLength];
		memcpy(newBuf, tval, tlen*sizeof(char));
		delete [] tval;
		tval = newBuf;
	}
	if (ch != Buffer::EoF) {
		tval[tlen++] = ch;
		NextCh();
	}
}



void Scanner::CreateHeapBlock() {
	void* newHeap;
	char* cur = (char*) firstHeap;

	while(((char*) tokens < cur) || ((char*) tokens > (cur + COCO_HEAP_BLOCK_SIZE))) {
		cur = *((char**) (cur + COCO_HEAP_BLOCK_SIZE));
		free(firstHeap);
		firstHeap = cur;
	}

	// COCO_HEAP_BLOCK_SIZE byte heap + pointer to next heap block
	newHeap = malloc(COCO_HEAP_BLOCK_SIZE + sizeof(void*));
	*heapEnd = newHeap;
	heapEnd = (void**) (((char*) newHeap) + COCO_HEAP_BLOCK_SIZE);
	*heapEnd = 0;
	heap = newHeap;
	heapTop = heap;
}

Token* Scanner::CreateToken() {
	Token *t;
	if (((char*) heapTop + (int) sizeof(Token)) >= (char*) heapEnd) {
		CreateHeapBlock();
	}
	t = (Token*) heapTop;
	heapTop = (void*) ((char*) heapTop + sizeof(Token));
	t->val = NULL;
	t->next = NULL;
	return t;
}

void Scanner::AppendVal(Token *t) {
	int reqMem = (tlen + 1) * sizeof(char);
	if (((char*) heapTop + reqMem) >= (char*) heapEnd) {
		if (reqMem > COCO_HEAP_BLOCK_SIZE) {
			printf("--- Too long token value\n");
			exit(1);
		}
		CreateHeapBlock();
	}
	t->val = (char*) heapTop;
	heapTop = (void*) ((char*) heapTop + reqMem);

	strncpy(t->val, tval, tlen);
	t->val[tlen] = L'\0';
}

Token* Scanner::NextToken() {
	while (ch == ' ' ||
			false
	) NextCh();

	int recKind = noSym;
	int recEnd = pos;
	t = CreateToken();
	t->pos = pos; t->col = col; t->line = line; t->charPos = charPos;
	int state = start.state(ch);
	tlen = 0; AddCh();

	switch (state) {
		case -1: { t->kind = eofSym; break; } // NextCh already done
		case 0: {
			case_0:
			if (recKind != noSym) {
				tlen = recEnd - t->pos;
				SetScannerBehindT();
			}
			t->kind = recKind; break;
		} // NextCh already done
		case 1:
			case_1:
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_2;}
			else {goto case_0;}
		case 2:
			case_2:
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_3;}
			else {goto case_0;}
		case 3:
			case_3:
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_4;}
			else {goto case_0;}
		case 4:
			case_4:
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_5;}
			else {goto case_0;}
		case 5:
			case_5:
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_6;}
			else {goto case_0;}
		case 6:
			case_6:
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_7;}
			else {goto case_0;}
		case 7:
			case_7:
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_8;}
			else {goto case_0;}
		case 8:
			case_8:
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')) {AddCh(); goto case_9;}
			else {goto case_0;}
		case 9:
			case_9:
			{t->kind = 1; break;}
		case 10:
			case_10:
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_11;}
			else {goto case_0;}
		case 11:
			case_11:
			recEnd = pos; recKind = 2;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_11;}
			else {t->kind = 2; break;}
		case 12:
			if (ch == 10) {AddCh(); goto case_13;}
			else {goto case_0;}
		case 13:
			case_13:
			{t->kind = 3; break;}
		case 14:
			case_14:
			recEnd = pos; recKind = 4;
			if ((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'Z') || ch == L'_' || (ch >= L'a' && ch <= L'z')) {AddCh(); goto case_14;}
			else {t->kind = 4; COCOCHAR_T *literal = coco_string_create(tval, 0, tlen); t->kind = keywords.get(literal, t->kind); coco_string_delete(literal); break;}
		case 15:
			case_15:
			if (ch == L'r') {AddCh(); goto case_16;}
			else {goto case_0;}
		case 16:
			case_16:
			if (ch == L't') {AddCh(); goto case_17;}
			else {goto case_0;}
		case 17:
			case_17:
			if (ch == L'e') {AddCh(); goto case_18;}
			else {goto case_0;}
		case 18:
			case_18:
			if (ch == L'x') {AddCh(); goto case_19;}
			else {goto case_0;}
		case 19:
			case_19:
			{t->kind = 5; break;}
		case 20:
			case_20:
			if (ch == L'r') {AddCh(); goto case_21;}
			else {goto case_0;}
		case 21:
			case_21:
			if (ch == L'a') {AddCh(); goto case_22;}
			else {goto case_0;}
		case 22:
			case_22:
			if (ch == L'g') {AddCh(); goto case_23;}
			else {goto case_0;}
		case 23:
			case_23:
			if (ch == L'm') {AddCh(); goto case_24;}
			else {goto case_0;}
		case 24:
			case_24:
			if (ch == L'e') {AddCh(); goto case_25;}
			else {goto case_0;}
		case 25:
			case_25:
			if (ch == L'n') {AddCh(); goto case_26;}
			else {goto case_0;}
		case 26:
			case_26:
			if (ch == L't') {AddCh(); goto case_27;}
			else {goto case_0;}
		case 27:
			case_27:
			{t->kind = 6; break;}
		case 28:
			case_28:
			if (ch == L't') {AddCh(); goto case_29;}
			else {goto case_0;}
		case 29:
			case_29:
			if (ch == L't') {AddCh(); goto case_30;}
			else {goto case_0;}
		case 30:
			case_30:
			if (ch == L'r') {AddCh(); goto case_31;}
			else {goto case_0;}
		case 31:
			case_31:
			if (ch == L'i') {AddCh(); goto case_32;}
			else {goto case_0;}
		case 32:
			case_32:
			if (ch == L'b') {AddCh(); goto case_33;}
			else {goto case_0;}
		case 33:
			case_33:
			if (ch == L'u') {AddCh(); goto case_34;}
			else {goto case_0;}
		case 34:
			case_34:
			if (ch == L't') {AddCh(); goto case_35;}
			else {goto case_0;}
		case 35:
			case_35:
			if (ch == L'e') {AddCh(); goto case_36;}
			else {goto case_0;}
		case 36:
			case_36:
			{t->kind = 7; break;}
		case 37:
			case_37:
			if (ch == L'r') {AddCh(); goto case_38;}
			else {goto case_0;}
		case 38:
			case_38:
			{t->kind = 8; break;}
		case 39:
			case_39:
			if (ch == L'n') {AddCh(); goto case_40;}
			else {goto case_0;}
		case 40:
			case_40:
			if (ch == L'i') {AddCh(); goto case_41;}
			else {goto case_0;}
		case 41:
			case_41:
			if (ch == L'f') {AddCh(); goto case_42;}
			else {goto case_0;}
		case 42:
			case_42:
			if (ch == L'o') {AddCh(); goto case_43;}
			else {goto case_0;}
		case 43:
			case_43:
			if (ch == L'r') {AddCh(); goto case_44;}
			else {goto case_0;}
		case 44:
			case_44:
			if (ch == L'm') {AddCh(); goto case_45;}
			else {goto case_0;}
		case 45:
			case_45:
			{t->kind = 9; break;}
		case 46:
			case_46:
			if (ch == L'o') {AddCh(); goto case_47;}
			else {goto case_0;}
		case 47:
			case_47:
			if (ch == L'n') {AddCh(); goto case_48;}
			else {goto case_0;}
		case 48:
			case_48:
			if (ch == L's') {AddCh(); goto case_49;}
			else {goto case_0;}
		case 49:
			case_49:
			if (ch == L't') {AddCh(); goto case_50;}
			else {goto case_0;}
		case 50:
			case_50:
			{t->kind = 10; break;}
		case 51:
			case_51:
			if (ch == L'a') {AddCh(); goto case_52;}
			else {goto case_0;}
		case 52:
			case_52:
			if (ch == L'm') {AddCh(); goto case_53;}
			else {goto case_0;}
		case 53:
			case_53:
			if (ch == L'p') {AddCh(); goto case_54;}
			else {goto case_0;}
		case 54:
			case_54:
			if (ch == L'l') {AddCh(); goto case_55;}
			else {goto case_0;}
		case 55:
			case_55:
			if (ch == L'e') {AddCh(); goto case_56;}
			else {goto case_0;}
		case 56:
			case_56:
			if (ch == L'r') {AddCh(); goto case_57;}
			else {goto case_0;}
		case 57:
			case_57:
			{t->kind = 11; break;}
		case 58:
			case_58:
			{t->kind = 15; break;}
		case 59:
			case_59:
			recEnd = pos; recKind = 1;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_59;}
			else if (ch == L'.') {AddCh(); goto case_10;}
			else {t->kind = 1; break;}
		case 60:
			recEnd = pos; recKind = 1;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_59;}
			else if (ch == L'x') {AddCh(); goto case_1;}
			else if (ch == L'.') {AddCh(); goto case_10;}
			else {t->kind = 1; break;}
		case 61:
			if (ch == L'v') {AddCh(); goto case_63;}
			else if (ch == L'f') {AddCh(); goto case_20;}
			else if (ch == L'a') {AddCh(); goto case_28;}
			else if (ch == L'u') {AddCh(); goto case_39;}
			else if (ch == L'c') {AddCh(); goto case_46;}
			else if (ch == L's') {AddCh(); goto case_51;}
			else {goto case_0;}
		case 62:
			recEnd = pos; recKind = 1;
			if ((ch >= L'0' && ch <= L'9')) {AddCh(); goto case_59;}
			else if (ch == L'.') {AddCh(); goto case_10;}
			else if (ch == L'd') {AddCh(); goto case_58;}
			else {t->kind = 1; break;}
		case 63:
			case_63:
			if (ch == L'e') {AddCh(); goto case_15;}
			else if (ch == L'a') {AddCh(); goto case_37;}
			else {goto case_0;}
		case 64:
			{t->kind = 16; break;}
		case 65:
			{t->kind = 17; break;}
		case 66:
			{t->kind = 18; break;}
		case 67:
			{t->kind = 19; break;}
		case 68:
			{t->kind = 20; break;}
		case 69:
			{t->kind = 21; break;}
		case 70:
			{t->kind = 22; break;}
		case 71:
			{t->kind = 23; break;}

	}
	AppendVal(t);
	return t;
}

void Scanner::SetScannerBehindT() {
	buffer->SetPos(t->pos);
	NextCh();
	line = t->line; col = t->col; charPos = t->charPos;
	for (int i = 0; i < tlen; i++) NextCh();
}

// get the next token (possibly a token already seen during peeking)
Token* Scanner::Scan() {
	if (tokens->next == NULL) {
		return pt = tokens = NextToken();
	} else {
		pt = tokens = tokens->next;
		return tokens;
	}
}

// peek for the next token, ignore pragmas
Token* Scanner::Peek() {
	do {
		if (pt->next == NULL) {
			pt->next = NextToken();
		}
		pt = pt->next;
	} while (pt->kind > maxT); // skip pragmas

	return pt;
}

// make sure that peeking starts at the current scan position
void Scanner::ResetPeek() {
	pt = tokens;
}

} // namespace
} // namespace

