//
//  PTChatSessionProtocols.h
//  PepperTalk
//
//  Created by HIMANSHU RETAREKAR on 14/01/15.
//  Copyright (c) 2015 Espreccino. All rights reserved.
//

#ifndef PepperTalk_PTChatSessionProtocols_h
#define PepperTalk_PTChatSessionProtocols_h

/** Implement this protocol to be able to provide a view for rendering custom data in chat stream uitableviewcell
 */
@protocol PTChatSessionCustomDataRendererProtocol <NSObject>

/** Actual view to be shown inside chat stream for given customData 
 @param customData customData passed by client on the other end in chat stream
 @return UIView which is to be rendered inside chat stream for given custom data
 */
- (UIView *) viewForMessageWithCustomData:(NSDictionary *)customData;
@end

/** Implement this protocol to be able to set configure chat session globally.
 */
@protocol PTChatSessionGlobalConfigurationProtocol <NSObject>

/** Set titleTextColor to customize the chat screen's title text color */
@property (strong, nonatomic) UIColor *titleTextColor;

/** Set subtitleTextColor to customize the chat screen's subTitle text color */
@property (strong, nonatomic) UIColor *subtitleTextColor;

/** Set outgoingBubbleColor to customize the outgoing message's bubble color */
@property (strong, nonatomic) UIColor *outgoingBubbleColor;

/** Set incomingBubbleColor to customize the incoming message's bubble color */
@property (strong, nonatomic) UIColor *incomingBubbleColor;

/** Set action toolbar's barTintColor */
@property (strong, nonatomic) UIColor *actionToolbarBarTintColor;

/** Set action toolbar's tint color */
@property (strong, nonatomic) UIColor *actionToolbarTintColor;

/** Set action toolbar's custom buttons. Pass NSArray of UIToolBarButtonItems */
@property (strong, nonatomic) NSArray *actionToolbarButtons;

/** Set a custom renderer object which confirms to PTChatSessionCustomDataRendererProtocol in order
 to provide view for custom data in chat stream
 */
@property (assign, nonatomic) id<PTChatSessionCustomDataRendererProtocol> customDataRenderer;
@end

#endif
