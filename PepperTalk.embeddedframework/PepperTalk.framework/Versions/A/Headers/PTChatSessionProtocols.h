//
//  PTChatSessionProtocols.h
//  PepperTalk
//
//  Created by HIMANSHU RETAREKAR on 14/01/15.
//  Copyright (c) 2015 Espreccino. All rights reserved.
//

#ifndef PepperTalk_PTChatSessionProtocols_h
#define PepperTalk_PTChatSessionProtocols_h

/** Implement this protocol to be able to customize chat UI.
 */
@protocol PTChatSessionAppearanceProtocol <NSObject>

/** Set outgoingBubbleColor to customize the outgoing message's bubble color */
@property (strong, nonatomic) UIColor *outgoingBubbleColor;

/** Set incomingBubbleColor to customize the incoming message's bubble color */
@property (strong, nonatomic) UIColor *incomingBubbleColor;

/** Set action toolbar's barTintColor */
@property (strong, nonatomic) UIColor *actionToolbarBarTintColor;

/** Set action toolbar's tint color */
@property (strong, nonatomic) UIColor *actionToolbarTintColor;

@end

#endif
