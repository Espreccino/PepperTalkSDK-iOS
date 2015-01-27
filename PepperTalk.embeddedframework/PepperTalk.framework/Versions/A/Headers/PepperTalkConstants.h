//
//  PepperTalkConstants.h
//  PepperTalk
//
//  Created by HIMANSHU RETAREKAR on 05/12/14.
//  Copyright (c) 2014 Espreccino. All rights reserved.
//

#ifndef PepperTalk_PepperTalkConstants_h
#define PepperTalk_PepperTalkConstants_h

/**
 A reserved key which assosiates a chat session with a particular context id
 */
extern NSString *const PTSessionOption_TopicId;
/**
 A reserved key which assosiates a chat session with a particular context title
 */
extern NSString *const PTSessionOption_TopicTitle;

/**
 A reserved key which is used to notify clients about unread count updates
 */
extern NSString *const PTUnreadCountUpdateNotification;
extern NSString *const PTUnreadCountUpdateNotification_ParticipantKey;
extern NSString *const PTUnreadCountUpdateNotification_TopicIdKey;
extern NSString *const PTUnreadCountUpdateNotification_UnreadCountKey;

/**
 A reserved key which is used to notify clients about incoming custom data
 */
extern NSString *const PTReceivedCustomDataNotification;
//MsgData related keys
extern NSString *const PTReceivedCustomDataNotification_MsgDataKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_ToKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_FromKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_TimestampKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_TopicIdKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_TopicTitleKey;
//Custom Data related keys
extern NSString *const PTReceivedCustomDataNotification_CustomDataKey;

/**
 A reserved key which is used to notify clients about participant info selection from action bar
 */
extern NSString *const PTActionBarParticipantInfoNotification;
extern NSString *const PTActionBarParticipantInfoNotification_participantKey;

/**
 A reserved key which is used to notify clients about topic info selection from action bar
 */
extern NSString *const PTActionBarTopicInfoNotification;
extern NSString *const PTActionBarTopicInfoNotification_topicIdKey;

#endif
