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
 Reserved keys which are used to get values from NSDictionary returned by unreadNotificationCount calls
 */
extern NSString *const PTUnreadCountQueryTotalUnreadCountKey;
extern NSString *const PTUnreadCountQueryParticipantsKey;
extern NSString *const PTUnreadCountQueryTopicsKey;


//================================================Notifications Related================================================//

/**
 Notification with name PTUnreadCountUpdateNotification is posted to notify observers about unread count updates. Notification userInfo has following format:
 {
     PTUnreadCountQueryTopicsKey : {
         # topic id : # unread count for the topic,
         # topic id : # unread count for the topic,
     }
     PTUnreadCountQueryTotalUnreadCountKey : # id of participant
 }
 */
extern NSString *const PTUnreadCountUpdateNotification;
extern NSString *const PTUnreadCountUpdateNotification_ParticipantKey;
extern NSString *const PTUnreadCountUpdateNotification_TopicIdKey;
extern NSString *const PTUnreadCountUpdateNotification_UnreadCountKey;

/**
 Notification with name PTReceivedCustomDataNotification is posted to notify observers about incoming custom data. Notification userInfo has the following format:
 {
     PTReceivedCustomDataNotification_MsgDataKey : {
        PTReceivedCustomDataNotification_MsgData_ToKey : # custom data receipient id
        PTReceivedCustomDataNotification_MsgData_FromKey : # custom data sender id
        PTReceivedCustomDataNotification_MsgData_TimestampKey : # custom data timestamp in epoch milliseconds
        PTReceivedCustomDataNotification_MsgData_TopicIdKey : # topic id
        PTReceivedCustomDataNotification_MsgData_TopicTitleKey : topic title
     }
     PTReceivedCustomDataNotification_CustomDataKey : # actual custom data from other end in form of NSDictionary
 }
 */
extern NSString *const PTReceivedCustomDataNotification;
extern NSString *const PTReceivedCustomDataNotification_MsgDataKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_ToKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_FromKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_TimestampKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_TopicIdKey;
extern NSString *const PTReceivedCustomDataNotification_MsgData_TopicTitleKey;
extern NSString *const PTReceivedCustomDataNotification_CustomDataKey;

#endif
