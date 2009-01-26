//
//  YLView.h
//  MacBlueTelnet
//
//  Created by Yung-Luen Lan on 2006/6/9.
//  Copyright 2006 yllan.org. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "CommonType.h"
#import "KOMouseHotspotHandler.h"

@class YLTerminal;
@class YLConnection;
@class YLMarkedTextView;
@class KOEffectView;
@class XIPortal;
@class XIIntegerArray;
@class KOTrackingRectData;

@interface YLView : NSTabView <NSTextInput> {	
	CGFloat _fontWidth;
	CGFloat _fontHeight;
	
	NSImage *_backedImage;
	
	NSTimer *_timer;
	int _x;
	int _y;
	
	id _markedText;
	NSRange _selectedRange;
	NSRange _markedRange;
	
	IBOutlet YLMarkedTextView *_textField;
	IBOutlet KOEffectView *_effectView;
    
    int _selectionLocation;
    int _selectionLength;
    
    XIPortal *_portal;
	
	XIIntegerArray *_ipTrackingRects;
	XIIntegerArray *_clickEntryTrackingRects;
	NSTrackingRectTag _exitTrackingRect;
	NSTrackingRectTag _pgUpTrackingRect;
	NSTrackingRectTag _pgDownTrackingRect;
	XIIntegerArray *_buttonTrackingRects;
	NSMutableArray *_trackingRectDataList;
	
	KOTrackingRectData *_clickEntryData;
	KOTrackingRectData *_buttonData;
	BOOL _isMouseInExitArea;
	BOOL _isMouseInPgUpArea;
	BOOL _isMouseInPgDownArea;
	BOOL _isInPortalMode;
	BOOL _isInUrlMode;
	NSCursor *_normalCursor;
	
	NSObject <KOMouseHotspotHandler> *_activeMouseHandler;
}
// TEST
- (void) tick: (NSArray *) a;


- (void)configure;

- (void)copy:(id)sender;
- (void)pasteWrap:(id)sender;
- (void)paste:(id)sender;
- (void)pasteColor:(id)sender;

- (void)displayCellAtRow:(int)r column:(int)c;
- (void)updateBackedImage;
- (void)drawSelection;
- (void)drawBlink;
- (void)refreshHiddenRegion;

- (void)clearSelection;

- (YLTerminal *)frontMostTerminal;
- (YLConnection *)frontMostConnection;
- (BOOL)connected;

- (void) extendBottomFrom: (int) start to: (int) end;
- (void) extendTopFrom: (int) start to: (int) end ;

- (void) drawStringForRow: (int) r context: (CGContextRef) myCGContext ;
- (void) updateBackgroundForRow: (int) r from: (int) start to: (int) end ;

- (int)x;
- (void)setX:(int)value;

- (int)y;
- (void)setY:(int)value;

- (float) fontWidth;
- (void) setFontWidth:(float)value;

- (float) fontHeight;
- (void) setFontHeight:(float)value;

- (BOOL) isInPortalState;
- (BOOL) isInUrlState;

- (NSString *) selectedPlainString ;
- (BOOL) hasBlinkCell ;

- (void)insertText:(id)aString withDelay:(int)microsecond;
/* Url Menu */

/* Portal */
- (void)updatePortal;
- (void)removePortal;
- (void)checkPortal;
- (void)resetPortal;
- (void)addPortalPicture: (NSString *) source 
				 forSite: (NSString *) siteName;

/* Hot Spots */
- (void)refreshAllHotSpots;
- (void)setActiveHandler: (NSObject <KOMouseHotspotHandler> *)handler;
- (void)removeActiveHandler;

/* ip seeker */
- (void)updateIPStateForRow: (int) r;
- (void)clearAllTrackingArea;
- (void)addToolTip: (NSString *)tooltip
			   row: (int)r
			column: (int)c
			length: (int)length;

/* post entry */
- (void)updateClickEntryForRow: (int) r;
- (void)updateExitArea;
- (void)updatePageUpArea;
- (void)updatePageDownArea;
- (void)updateButtonAreaForRow: (int) r;

// safe_paste
- (void)confirmPaste:(NSWindow *)sheet returnCode:(int)returnCode contextInfo:(void *)contextInfo;
- (void)confirmPasteWrap:(NSWindow *)sheet returnCode:(int)returnCode contextInfo:(void *)contextInfo;
- (void)confirmPasteColor:(NSWindow *)sheet returnCode:(int)returnCode contextInfo:(void *)contextInfo;
- (void)performPaste;
- (void)performPasteWrap;
- (void)performPasteColor;

// Test for effect view
- (KOEffectView *) getEffectView ;

@end
