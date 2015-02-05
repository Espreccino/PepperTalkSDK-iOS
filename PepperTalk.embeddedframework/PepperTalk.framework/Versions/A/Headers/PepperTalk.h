//
//  PepperTalk.h
//  PepperTalk
//
//  Created by HIMANSHU RETAREKAR on 25/11/14.
//  Copyright (c) 2014 Espreccino. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PepperTalkConstants.h"
#import "PTChatSessionProtocols.h"

/** This is the go to class for developers. Most of the functionality of the kit is exposed through this class.
 */
@interface PepperTalk : NSObject

/** Pass clientId to identify the client app */
@property (nonatomic, copy) NSString *clientId;

/** Pass clientSecret to authorize the client app to use the kit*/
@property (nonatomic, copy) NSString *clientSecret;

/** To receive remote notifications, pass deviceToken to PepperTalk*/
@property (nonatomic, copy) NSData *deviceToken;

/** Query loggedInParticipant to check for valid login credentials*/
@property (nonatomic, readonly) NSString *loggedInParticipant;

/** Use globalConfigurator object to set configuration properties at app level */
@property (nonatomic, readonly) NSObject<PTChatSessionGlobalConfigurationProtocol> *globalConfigurator;

/**
 PepperTalk instance creation
 
 Type of Result - PepperTalk singleton instance.
 @return A singleton instance of PepperTalk class. Use this instance to avail kit functionality.
 */
+ (instancetype)sharedInstance;

/**
 Pass logged in user information to PepperTalk
 
 @param username The logged in user's username
 @param fullName The logged in user's full name
 @param profilePicture The logged in user's profile picture url
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete
 */
- (NSError *) setLoggedInUserWithUsername:(NSString *)username
                                 fullName:(NSString *)fullName
                           profilePicture:(NSString *)profilePicture
                          completion:(void(^)(NSError *))completion;

/**
 Present chat session view modally
 
 @param participant Pass username of the user with whom chat session is to be initiated
 @param options Pass additional configurable options for the chat session. Currently we only support PTSessionOption_TopicId and PTSessionOption_TopicTitle options.
 @param presentingViewController Pass the view controller which will be used to present the chat session modally
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) presentChatSessionWithParticipant:(NSString *)participant
                                  sessionOptons:(NSDictionary *)options
                       presentingViewController:(UIViewController *)presentingViewController;

/**
 Create and return chat session view
 
 @param participant Pass username of the user with whom chat session is to be initiated
 @param options Pass additional configurable options for the chat session. Currently we only support PTSessionOption_TopicId and PTSessionOption_TopicTitle options.
 @param error If an error occurs, the error parameter will be set and the return value will be nil.
 @return An instance of UIViewController which can be shown on screen in any way.
 */
- (UIViewController *) chatSessionWithParticipant:(NSString *)participant
                                     sessionOptons:(NSDictionary *)options
                                             error:(NSError **)error;

/**
 Forward the received remote notification to PepperTalk to be handled by us
 
 @param notification The dictionary containing the received notification.
 @param presentingViewController Pass the view controller which will be used to present handled notification
 @return If notification is handled by PepperTalk, returns YES else returns NO
 */
- (BOOL) handleRemoteNotification:(NSDictionary *)notification
         presentingViewController:(UIViewController *)presentingViewController;

/**
 Show list of topics under which you have had conversation with participant
 
 @param participants List of participants which are to be applied as filter while showing topics.
 Pass nil to disable filter
 @param presentingViewController Pass the view controller which will be used to present handled notification
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) presentAllTopicsFilterByParticipants:(NSArray *)participants
                      presentingViewController:(UIViewController *)presentingViewController;

/**
 Get view which shows list of topics under which you have had conversation with participant
 
 @param participants List of participants which are to be applied as filter while showing topics.
 Pass nil to disable filter
 @param error If an error occurs, the error parameter will be set and the return value will be nil.
 @return If operation could not be completed, it returns nil. View if the operation could complete successfully
 */
- (UIViewController *) allTopicsFilterByParticipants:(NSArray *)participants error:(NSError **)error;

/**
 Show list of participants with whom you have had conversation for this topic
 
 @param topicIds List of topicsIds which are to be applied as filter while showing participants.
 Pass nil to disable filter
 @param presentingViewController Pass the view controller which will be used to present handled notification
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) presentAllParticipantsFilterByTopics:(NSArray *)topicIds
                      presentingViewController:(UIViewController *)presentingViewController;

/**
 Get view which shows list of participants with whom you have had conversation for this topic
 
 @param topicIds List of topicsIds which are to be applied as filter while showing participants.
 Pass nil to disable filter
 @param error If an error occurs, the error parameter will be set and the return value will be nil.
 @return If operation could not be completed, it returns nil. View if the operation could complete successfully
 */
- (UIViewController *) allParticipantsFilterByTopics:(NSArray *)topicIds error:(NSError **)error;

/**
 Create a new group
 
 @param groupId The id which you would like to use for the new group. It should contain a prefix 'grp:'. E.g 'grp:usc_friends'
 @param groupName The name you would like to use for the group "USC College Friends"
 @param profilePicture The groups profile picture url
 @param members Array of member's user ids.
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) createGroupWithId:(NSString *)groupId
                           name:(NSString *)groupName
                 profilePicture:(NSString *)profilePicture
                        members:(NSArray *)members
                     completion:(void(^)(NSError *))completion;

/**
 Update group properties
 
 @param groupId The id of the group which you would like to update
 @param newName Set newName if you would like to update name of the group. If set to nil, will not update the name
 @param newProfilePicture Set profilePicture if you would like to update profile pic of the group. If set to nil, will not update the profile pic.
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) updateGroupWithId:(NSString *)groupId
                           name:(NSString *)newName
                 profilePicture:(NSString *)newProfilePicture
                     completion:(void(^)(NSError *))completion;

/**
 Add members to group
 
 @param groupId The id of the group which you would like to update
 @param newMembers Pass array of user ids which are to be added as group members
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) addMembers:(NSArray *)newMembers
           toGroupWithId:(NSString *)groupId
              completion:(void(^)(NSError *))completion;

/**
 Remove members from group
 
 @param groupId The id of the group which you would like to update
 @param membersToBeRemoved Pass array of user ids which are to be removed as group members
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) removeMembers:(NSArray *)membersToBeRemoved
            fromGroupWithId:(NSString *)groupId
                 completion:(void(^)(NSError *))completion;

/**
 Delete group
 
 @param groupId The id of the group which you would like to update
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) deleteGroupWithId:(NSString *)groupId
                     completion:(void(^)(NSError *))completion;

/**
 Reserved keys which are used to get values from NSDictionary returned by
 - (NSDictionary *) unreadNotificationCountForTopic:(NSString *)topicId
 filterByParticipants:(NSArray *)participants;
 &
 - (NSDictionary *) unreadNotificationCountForParticipant:(NSString *)participant
 filterByTopics:(NSArray *)topicIds;
 */
extern NSString *const PTUnreadCountQueryTotalUnreadCountKey;
extern NSString *const PTUnreadCountQueryParticipantsKey;
extern NSString *const PTUnreadCountQueryTopicsKey;
extern NSString *const PTUnreadCountQueryTopicIdKey;
extern NSString *const PTUnreadCountQueryParticipantKey;
extern NSString *const PTUnreadCountQueryUnreadCountKey;

/**
 Get unread notifications count for a topic
 
 @param topicId The topicId whose unread notifications count is to be returned
 @param participants List of participants which are to be applied as filter while showing unread notifications count. Pass nil to disable filter
 @return List of participant:unreadCount tuple. Nil if the operation could not complete successfully
 */
- (NSDictionary *) unreadNotificationCountForTopic:(NSString *)topicId
                              filterByParticipants:(NSArray *)participants;

/**
 Get unread notifications count for a participant
 
 @param participant The participant whose unread notifications count is to be returned
 @param topicIds List of topics which are to be applied as filter while showing unread notifications count. Pass nil to disable filter
 @return List of topicId:unreadCount tuple. Nil if the operation could not complete successfully
 */
- (NSDictionary *) unreadNotificationCountForParticipant:(NSString *)participant
                                          filterByTopics:(NSArray *)topicIds;

/**
 Use this method to enable in-app notification. Disabled by default
 
 @param presentingViewController Pass the view controller which will be used to present in-app notifications. PepperTalk will retain the presentingViewController. Disable in-app notifications to release presentingViewController
 */
- (void) enableInAppNotificationsInViewController:(UIViewController *)presentingViewController;

/**
 Use this method to disable in-app notification.
 */
- (void) disableInAppNotifications;


//Custom Messages
/**
 Use this method to send custom message to any participant user or group. The client at the other end will get a notification PTReceivedCustomDataNotification. The notification info can be queried for custom data, sender and timestamp. Use PTReceivedCustomDataNotification_CustomDataKey, PTReceivedCustomDataNotification_FromKey, PTReceivedCustomDataNotification_TimestampKey respectively to query.
 Max allowed size for custom data is 2KB.
 
 @param customData Data to be passed to participant client. Only supported format is JSON
 @param notificationText Text that will be shown in remote notifications. If text is set to nil, notification will not be sent out.
 @param participant The participant whose clients should get the callback with the custom data
 @param options Pass additional configurable options for the chat session. Currently we only support PTSessionOption_TopicId for this call.
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete
 */
- (NSError *) sendCustomData:(NSDictionary *)customData
                    withText:(NSString *)notificationText
               toParticipant:(NSString *)participant
               sessionOptons:(NSDictionary *)options
                  completion:(void(^)(NSError * err))completion;

/**
 Use this method to send custom message to any participant user or group in chat stream. The client on other end can then show a custom view inside the chat interface.
 Max allowed size for custom data is 2KB.
 @param customData Data to be passed to participant client. Only supported format is JSON
 @param notificationText Text that will be shown in remote notifications. If text is set to nil, notification will not be sent out.
 @param participant The participant whose clients should get the callback with the custom data
 @param options Pass additional configurable options for the chat session. Currently we only support PTSessionOption_TopicId for this call.
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete.
 */
- (NSError *) sendCustomDataInChatStream:(NSDictionary *)customData
                                 withText:(NSString *)notificationText
                            toParticipant:(NSString *)participant
                            sessionOptons:(NSDictionary *)options
                               completion:(void(^)(NSError * err))completion;

@end
