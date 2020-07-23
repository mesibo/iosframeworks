/** Copyright (c) 2019 Mesibo
 * https://mesibo.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the terms and condition mentioned
 * on https://mesibo.com as well as following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions, the following disclaimer and links to documentation and
 * source code repository.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of Mesibo nor the names of its contributors may be used to
 * endorse or promote products derived from this software without specific prior
 * written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Documentation
 * https://mesibo.com/documentation/
 *
 * Source Code Repository
 * https://github.com/mesibo/ui-modules-ios
 *
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>



#define LOGIN_PROCESS_BUNDLE        @"MesiboUIHelperResource"
#define LOGIN_PROCESS_STORY_BOARD   @"Main"
#define WELCOME_BUNDLE              @"MesiboUIHelperResource"
#define WELCOME_STORY_BOARD         @"WelcomeLaunch"



#define LOGIN_SIGNIN                0
#define LOGIN_FORGOT_PASSWORD       1


#define ACTION_REGISTER_NUMBER      5
#define ACTION_HAVE_OTP             6


#define ACTION_VERIFY_NUMBER        10
#define ACTION_START_AGAIN          11


@interface WelcomeBanner : NSObject
@property (strong, nonatomic) NSString *mTitle;
@property (strong, nonatomic) NSString *mDescription;
@property (strong, nonatomic) UIImage *mImage;
@property (nonatomic) uint32_t mColor;
@end

@interface MesiboUiHelperConfig : NSObject
@property (strong,nonatomic) NSString *mCountryCode;
@property (strong,nonatomic) NSString *mAppName;
@property (strong,nonatomic) NSString *mAppTag;
@property (strong,nonatomic) NSString *mAppUrl;
@property (strong,nonatomic) NSString *mAppWriteUp;
@property (nonatomic) uint32_t mBackgroundColor;
@property (nonatomic) uint32_t mButtonBackgroundColor;
@property (nonatomic) uint32_t mTextColor;
@property (nonatomic) uint32_t mSecondaryTextColor;
@property (nonatomic) uint32_t mButtonTextColor;
@property (nonatomic) uint32_t mBannerTitleColor;
@property (nonatomic) uint32_t mBannerDescColor;
@property (nonatomic) uint32_t mErrorTextColor;

@property (strong,nonatomic) NSArray *mBanners;
@end


typedef void (^WelcomeBlock)(UIViewController * viewController, BOOL result);
typedef void (^PhoneVerificationResultBlock)(BOOL result);
typedef void (^PhoneVerificationBlock)(id caller, NSString* phone, NSString* code, PhoneVerificationResultBlock resultBlock);


@interface MesiboUIHelper : NSObject
@property (strong,nonatomic) UIViewController* mParentViewController;
+ (UIViewController *) getWelcomeViewController:(WelcomeBlock)handler;
+ (UIViewController *) startMobileVerification:(PhoneVerificationBlock)handler;
+(MesiboUiHelperConfig *) getUiConfig;
+(void) setUiConfig:(MesiboUiHelperConfig *)config;
@end




