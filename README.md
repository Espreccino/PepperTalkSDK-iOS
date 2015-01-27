<p align="center">
  <img src="http://espreccino.getpeppertalk.com/images/logo.png" />
</p>

PepperTalkSDK-iOS
=============

[PepperTalkSDK-iOS](http://espreccino.getpeppertalk.com) allows developers to develop apps that integrate the PepperTalk functionality in their apps.

# Overview

The primary purpose of the SDK is to make it easy to use the PepperTalk platform. It provides functionality to initiate chat between two clients. Read below for additional information, or check out the [complete documentation](http://espreccino.github.io/PepperTalkSDK-iOS/) for a look at all the classes available with the SDK.

This document contains the following sections:

- [Requirements](#requirements)
- [Download & Extract](#download)
- [Xcode Setup](#xcode) 
- [Modify Code](#modify)

<a id="requirements"></a> 
## Requirements

The SDK runs on devices with iOS 7.0 or higher.

<a id="download"></a> 
## Download the SDK

1. (Manual) 
    * Download PepperTalk.embeddedframework and Dependencies Resources from github.
    * Move the folders into your project directory. We usually put 3rd-party code into a subdirectory named `Vendor`, so we move the directory into it.
  
2. (Cocoapods)
    * Install Cocoapods, if already not installed
    * Add "pod PepperTalkSDK-iOS" to your podfile
    * Run pod install
  
<a id="xcode"></a> 
## Xcode Setup (Skip step if using CocoaPods)

1. Drag & drop `PepperTalk.embeddedframework` from your project directory to your Xcode project.

2. Similar to above, our projects have a group `Vendor`, so we drop it there.

3. Select `Create groups for any added folders` and set the checkmark for your target. Then click `Finish`.

4. Select your project in the `Project Navigator` (⌘+1).

5. Select your app target.

6. Select the tab `Build Phases`.

7. Expand `Link Binary With Libraries`.

8. Add the following system frameworks, if they are missing:
    - `Accelerate`
    - `AssetsLibrary`
    - `CoreData`
    - `CoreGraphics`
    - `CoreImage`
    - `CoreLocation`
    - `Foundation`
    - `ImageIO`
    - `MapKit`
    - `MessageUI`
    - `MobileCoreServices`
    - `QuartzCore`
    - `Security`
    - `SystemConfiguration`
    - `UIKit`

9. Add the following libraries, if they are missing;
    - `icucore`

<a id="modify"></a> 
## Modify Code 

### Objective-C
1. Open your `AppDelegate.m` file.

2. Add the following line at the top of the file below your own #import statements:

        #import <PepperTalk/PepperTalkSDK.h>

3. Search for the method `application:didFinishLaunchingWithOptions:`

4. Add the following lines to setup PepperTalk:

        [PepperTalk sharedInstance].clientId = @"YOUR_CLIENT_ID";
        [PepperTalk sharedInstance].clientSecret = @"YOUR_CLIENT_SECRET";
        [[PepperTalk sharedInstance] enableInAppNotificationsInViewController:self.window.rootViewController]; //To enable in-app notifications

5. To enable Remote Notifications
    * Enable remote notifications as described in [Apple Documentation](https://developer.apple.com/library/ios/documentation/NetworkingInternet/Conceptual/RemoteNotificationsPG/Chapters/IPhoneOSClientImp.html#//apple_ref/doc/uid/TP40008194-CH103-SW2)
    * Search for method `application:didRegisterForRemoteNotificationsWithDeviceToken`
    * Add following line of code
      * `[PepperTalk sharedInstance].deviceToken = deviceToken;`
    * Search for method `application:didReceiveRemoteNotification:`
    * Add following line of code
      * `[[PepperTalk sharedInstance] handleRemoteNotification:userInfo presentingViewController:self.window.rootViewController];`

6. Starting with iOS 8, to enable location sharing in PepperTalk, you must set a string for the key `NSLocationWhenInUseUsageDescription` or `NSLocationAlwaysUsageDescription` in your app's Info.plist file. For more information refer [Apple Documentation](https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html#//apple_ref/doc/uid/TP40009251-SW18). If neither of the keys are found in the client's Info.plist file, then the location sharing opiton will not be available.
