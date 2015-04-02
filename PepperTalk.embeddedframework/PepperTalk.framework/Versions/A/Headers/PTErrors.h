//
//  PTErrors.h
//  PepperTalk
//
//  Created by HIMANSHU RETAREKAR on 26/11/14.
//  Copyright (c) 2014 Espreccino. All rights reserved.
//

#import <Foundation/Foundation.h>

// Domains for PTErrors
extern NSString *const kPTServerErrorDomain;
extern NSString *const kPTHttpErrorDomain;
extern NSString *const kPTGeneralErrorDomain;


/** Base value of errors */
typedef NS_ENUM(NSInteger, PTErrorBases) {
    
    PTHttpErrorBase      = 100,
    PTHttpErrorMax       = 999,
    
    PTGeneralErrorBase   = 2000,
    PTGeneralErrorMax    = 2999,
};

/** List of all PepperTalk issued errors
 */
typedef NS_ENUM(NSInteger, EPTGeneralError) {
    
    PTGeneralErrorNoError            = 0 + PTGeneralErrorBase,
    PTGeneralErrorSomeError          = 1 + PTGeneralErrorBase,
    PTGeneralErrorNullPointer        = 2 + PTGeneralErrorBase,
    PTGeneralErrorBadHandle          = 3 + PTGeneralErrorBase,
    PTGeneralErrorNoMemory           = 4 + PTGeneralErrorBase,
    PTGeneralErrorBadParameter       = 5 + PTGeneralErrorBase,
    PTGeneralErrorBadState           = 6 + PTGeneralErrorBase,
    PTGeneralErrorNoAccess           = 7 + PTGeneralErrorBase,
    PTGeneralErrorInUse              = 8 + PTGeneralErrorBase,
    PTGeneralErrorNotInitialized     = 9 + PTGeneralErrorBase,
    PTGeneralErrorNotFound           = 10 + PTGeneralErrorBase,
    PTGeneralErrorExists             = 11 + PTGeneralErrorBase,
    PTGeneralErrorIOError            = 12 + PTGeneralErrorBase,
    PTGeneralErrorTooMany            = 13 + PTGeneralErrorBase,
    PTGeneralErrorBusy               = 14 + PTGeneralErrorBase,
    PTGeneralErrorIncomplete         = 15 + PTGeneralErrorBase,
    PTGeneralErrorEnd                = 16 + PTGeneralErrorBase,
    PTGeneralErrorWriteProtect       = 17 + PTGeneralErrorBase,
    PTGeneralErrorNotReady           = 18 + PTGeneralErrorBase,
    PTGeneralErrorDiskFull           = 19 + PTGeneralErrorBase,
    PTGeneralErrorBadIndex           = 20 + PTGeneralErrorBase,
    PTGeneralErrorBadFormat          = 21 + PTGeneralErrorBase,
    PTGeneralErrorNotImplemented     = 22 + PTGeneralErrorBase,
    PTGeneralErrorBadStatus          = 23 + PTGeneralErrorBase,
    PTGeneralErrorUnexpected         = 24 + PTGeneralErrorBase,
    PTGeneralErrorExpected           = 25 + PTGeneralErrorBase,
    PTGeneralErrorPreconditionFailed = 26 + PTGeneralErrorBase,
    PTGeneralErrorVerifyFailed       = 27 + PTGeneralErrorBase,
    PTGeneralErrorRPC                = 28 + PTGeneralErrorBase,
    PTGeneralErrorTimeout            = 29 + PTGeneralErrorBase,
    PTGeneralErrorBadProtocol        = 30 + PTGeneralErrorBase,
    PTGeneralErrorInvalidType        = 31 + PTGeneralErrorBase,
    PTGeneralErrorUserCanceled       = 32 + PTGeneralErrorBase,
    PTGeneralErrorTooLong            = 33 + PTGeneralErrorBase,
    PTGeneralErrorBadSequence        = 34 + PTGeneralErrorBase
};
