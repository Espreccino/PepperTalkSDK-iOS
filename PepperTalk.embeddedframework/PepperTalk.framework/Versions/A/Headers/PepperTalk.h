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

/** This is the main class of the Pepper Talk . Its the entry point into Pepper Talk.
 This class lets users initialize the SDK & initiate chat session, access unreadcounts & pass custom data
 between two or more endpoints.
 */
@interface PepperTalk : NSObject

/** Pass clientId to identify the client app */
@property (nonatomic, copy) NSString *clientId;

/** Pass clientSecret to authorize the client app to use PepperTalk SDK*/
@property (nonatomic, copy) NSString *clientSecret;

/** To receive remote notifications, pass deviceToken to PepperTalk*/
@property (nonatomic, copy) NSData *deviceToken;

/** Query loggedInParticipant to check for valid login credentials*/
@property (nonatomic, readonly) NSString *loggedInParticipant;

@property (nonatomic) BOOL initialised;

/** Pass your Google API Key to enable Location sharing. If not set, location sharing option will not be available */
@property (nonatomic, copy) NSString *googleAPIKey;

/** Use globalConfigurator object to set configuration properties at app level */
@property (nonatomic, readonly) NSObject<PTChatSessionGlobalConfigurationProtocol> *globalConfigurator;

/**
 PepperTalk instance creation
 
 Type of Result - PepperTalk singleton instance.
 @return A singleton instance of PepperTalk class. Use this instance to initialise & then use Pepper Talk.
 */
+ (instancetype)sharedInstance;

/**
 Initialise the SDK with logged in user's details
 
 @param username The logged in user's username
 @param fullName The logged in user's full name
 @param profilePicture The logged in user's profile picture url
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete
 */
- (NSError *) initialiseWithUsername:(NSString *)username
                            fullName:(NSString *)fullName
                      profilePicture:(NSString *)profilePicture
                          completion:(void(^)(NSError *err))completion;

/** Log curent logged in user out
 
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete
 */
- (NSError *) logoutWithCompletion:(void(^)(NSError *err))completion;

/**
 Update user profile information
 
 @param username username of the user whose information is to be updated
 @param updatedFullName New Full name. Pass Nil if full name is not to be updated.
 @param updatedProfilePicture New profile picture. Pass Nil if profile picture is not to be updated.
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete
 */
- (NSError *) updateUserProfile:(NSString *)username
                       fullName:(NSString *)updatedFullName
                 profilePicture:(NSString *)updatedProfilePicture
                     completion:(void(^)(NSDictionary *userInfo, NSError *err))completion;

/**
 Present chat session view modally
 
 @param participant Pass username of the user with whom chat session is to be initiated
 @param topicId an id for the topic
 @param topicTitle title for the topic, this will be displayed on the chat window, so ensure it contains a meaningful text representation of the topic
 @param presentingViewController Pass the view controller which will be used to present the chat session modally
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) presentChatSessionWithParticipant:(NSString *)participant
                                        topicId:(NSString *)topicId
                                     topicTitle:(NSString *)topicTitle
                       presentingViewController:(UIViewController *)presentingViewController;

/**
 Create and return chat session view
 
 @param participant Pass username of the user with whom chat session is to be initiated
 @param topicId an id for the topic
 @param topicTitle title for the topic, this will be displayed on the chat window, so ensure it contains a meaningful text representation of the topic
 @param error If an error occurs, the error parameter will be set and the return value will be nil.
 @return An instance of UIViewController which can be shown on screen in any way.
 */
- (UIViewController *) chatSessionWithParticipant:(NSString *)participant
                                          topicId:(NSString *)topicId
                                       topicTitle:(NSString *)topicTitle
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
- (UIViewController *) allTopicsFilterByParticipants:(NSArray *)participants
                                               error:(NSError **)error;

/**
 Get list of topics under which you have had conversation with these participants
 
 @param participants List of participants which are to be applied as filter while showing topics.
 Pass nil to disable filter
 @param error If an error occurs, the error parameter will be set and the return value will be nil.
 @return If operation could not be completed, it returns nil. If operation succesfull find information in this format
 {
     # id of user : {
         topics : {
             # id of topic : {
                 count   : # total messages in this topic for this user
                 unread  : # total unread messages within those messages
                 last_message_timestamp: # unix timestamp in millis for the last message in them
                 topic_title : # description of the topic
                 topic_id    : # id of the topic
             }
         }
         user_name : # user name
         user_id   : # id of the user
     }
 }
 */
- (NSDictionary *) allTopicsSummaryFilterByParticipants:(NSArray *)participants
                                                  error:(NSError **)error;

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
 Get list of participants with whom you have had conversation for these topics
 
 @param topicIds List of topicsIds which are to be applied as filter while showing participants.
 Pass nil to disable filter
 @param error If an error occurs, the error parameter will be set and the return value will be nil.
 @return If operation could not be completed, it returns nil. View if the operation could complete successfully
 */
- (UIViewController *) allParticipantsFilterByTopics:(NSArray *)topicIds
                                               error:(NSError **)error;

/**
 Get list of participants with whom you have had conversation for these topics
 
 @param topicIds List of topicsIds which are to be applied as filter while showing participants.
 Pass nil to disable filter
 @param error If an error occurs, the error parameter will be set and the return value will be nil.
 @return If operation could not be completed, it returns nil. If operation succesfull find information in this format
 {
     # id of topic : {
         users : {
             # id of participant : {
                 count   : # total messages in this topic for this user
                 unread  : # total unread messages within those messages
                 last_message_timestamp: # unix timestamp in millis for the last message in them
                 user_name : # user name
                 user_id   : # id of the user
             }
         }
         topic_title : # description of the topic
         topic_id    : # id of the topic
     }
 }
 */
- (NSDictionary *) allParticipantsSummaryFilterByTopics:(NSArray *)topicIds
                                                  error:(NSError **)error;

/**
 Create a new closed group
 
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
                     completion:(void(^)(NSDictionary *groupInfo, NSError *err))completion;

/**
 Create a new public group. Public groups are open to all the users and anybody can join the group.
 
 @param groupId The id which you would like to use for the new group. It should contain a prefix 'grp:'. E.g 'grp:usc_friends'
 @param groupName The name you would like to use for the group "USC College Friends"
 @param profilePicture The groups profile picture url
 @param members Array of member's user ids.
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) createPublicGroupWithId:(NSString *)groupId
                                 name:(NSString *)groupName
                       profilePicture:(NSString *)profilePicture
                              members:(NSArray *)members
                           completion:(void(^)(NSDictionary *groupInfo, NSError *err))completion;

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
                     completion:(void(^)(NSDictionary *groupInfo, NSError *err))completion;

/**
 Add members to group
 
 @param groupId The id of the group which you would like to update
 @param newMembers Pass array of user ids which are to be added as group members
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) addMembers:(NSArray *)newMembers
           toGroupWithId:(NSString *)groupId
              completion:(void(^)(NSDictionary *groupInfo, NSError *err))completion;

/**
 Remove members from group
 
 @param groupId The id of the group which you would like to update
 @param membersToBeRemoved Pass array of user ids which are to be removed as group members
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) removeMembers:(NSArray *)membersToBeRemoved
            fromGroupWithId:(NSString *)groupId
                 completion:(void(^)(NSDictionary *groupInfo, NSError *err))completion;

/**
 Delete group
 
 @param groupId The id of the group which you would like to update
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) deleteGroupWithId:(NSString *)groupId
                     completion:(void(^)(NSDictionary *groupInfo, NSError *err))completion;

/**
 Block a list of participants, users or groups. Once a participant is blocked none of the messages from that participant will be delivered to the user. If the participant is a group all messages to the group sent by anybody will be dropped.
 
 @param participantsToBeBlocked Pass array of participants which are to be blocked
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) blockParticipants:(NSArray *)participantsToBeBlocked
                     completion:(void(^)(NSDictionary *userInfo, NSError *err))completion;

/**
 Unblock a list of participants, users or groups.
 
 @param participantsToBeUnblocked Pass array of participants which are to be unblocked
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) unblockParticipants:(NSArray *)participantsToBeUnblocked
                       completion:(void(^)(NSDictionary *userInfo, NSError *err))completion;

/**
 Mute a list of participants, users or groups. Once a participant is muted none of the messages from that participant will be notified, messages will be delivered to the users but remote notifications will be disabled.
 
 @param participantsToBeMuted Pass array of participants which are to be muted
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) muteParticipants:(NSArray *)participantsToBeMuted
                    completion:(void(^)(NSDictionary *userInfo, NSError *err))completion;

/**
 Unmute a list of participants, users or groups.
 
 @param participantsToBeUnmuted Pass array of participants which are to be unmuted
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) unmuteParticipants:(NSArray *)participantsToBeUnmuted
                      completion:(void(^)(NSDictionary *userInfo, NSError *err))completion;

/**
 Get information for a user.
 
 @param userId The id of the user of which you would like to get information
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) getUserInfo:(NSString *)userId
               completion:(void(^)(NSDictionary *userInfo, NSError *err))completion;

/**
 Get information for a group.
 
 @param groupId The id of the group of which you would like to get information
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete successfully
 */
- (NSError *) getGroupInfo:(NSString *)groupId
                completion:(void(^)(NSDictionary *groupInfo, NSError *err))completion;

/**
 Get unread notifications count for a topic
 
 @param topicId The topicId whose unread notifications count is to be returned
 @param participants List of participants which are to be applied as filter while showing unread notifications count. Pass nil to disable filter
 @return Nil if the operation could not complete successfully. If operation succesfull, information returned is in following format:
 {
    PTUnreadCountQueryParticipantsKey : {
        # participant id : # unread count for the participant,
        # participant id : # unread count for the participant,
    }
    PTUnreadCountQueryTotalUnreadCountKey : # total unread count across all participants
 }
 */

- (NSDictionary *) unreadNotificationCountForTopic:(NSString *)topicId
                              filterByParticipants:(NSArray *)participants;

/**
 Get unread notifications count for a participant
 
 @param participant The participant whose unread notifications count is to be returned
 @param topicIds List of topics which are to be applied as filter while showing unread notifications count. Pass nil to disable filter
 @return Nil if the operation could not complete successfully. If operation succesfull, information returned is in following format:
 {
     PTUnreadCountQueryTopicsKey : {
         # topic id : # unread count for the topic,
         # topic id : # unread count for the topic,
     }
     PTUnreadCountQueryTotalUnreadCountKey : # total unread count across all topics
 }
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
 @param topicId an id for the topic
 @param topicTitle title for the topic, this will be displayed on the chat window, so ensure it contains a meaningful text representation of the topic
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete
 */
- (NSError *) sendCustomData:(NSDictionary *)customData
                    withText:(NSString *)notificationText
               toParticipant:(NSString *)participant
                     topicId:(NSString *)topicId
                  topicTitle:(NSString *)topicTitle
                  completion:(void(^)(NSError * err))completion;

/**
 Use this method to send custom message to any participant user or group in chat stream. The client on other end can then show a custom view inside the chat interface.
 Max allowed size for custom data is 2KB.
 @param customData Data to be passed to participant client. Only supported format is JSON
 @param notificationText Text that will be shown in remote notifications. If text is set to nil, notification will not be sent out.
 @param participant The participant whose clients should get the callback with the custom data
 @param topicId an id for the topic
 @param topicTitle title for the topic, this will be displayed on the chat window, so ensure it contains a meaningful text representation of the topic
 @param completion Completion callback with results of operation
 @return If operation could not be completed, it returns the error. Nil if the operation could complete.
 */
- (NSError *) sendCustomDataInChatStream:(NSDictionary *)customData
                                 withText:(NSString *)notificationText
                            toParticipant:(NSString *)participant
                                 topicId:(NSString *)topicId
                              topicTitle:(NSString *)topicTitle
                               completion:(void(^)(NSError * err))completion;

@end
