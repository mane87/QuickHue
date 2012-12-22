//
//  DPHue.h
//  HueProto
//
//  Created by Dan Parsons on 12/19/12.
//  Copyright (c) 2012 Dan Parsons. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPJSONSerializable.h"

@interface DPHue : NSObject <DPJSONSerializable, NSCoding>

@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong, readonly) NSString *deviceType;
@property (nonatomic, strong, readonly) NSURL *getURL;
@property (nonatomic, strong, readonly) NSURL *putURL;
@property (nonatomic, strong, readonly) NSString *host;
@property (nonatomic, strong, readonly) NSString *swversion;
@property (nonatomic, strong, readonly) NSArray *lights;
@property (nonatomic, readonly) BOOL authenticated;

+ (NSString *)generateUsername; // hash of hostname

- (id)initWithHueControllerIP:(NSString *)ip;
- (void)readWithCompletion:(void (^)(DPHue *hue, NSError *err))block;
- (void)registerUsername;
- (void)allLightsOff;
- (void)allLightsOn;
- (void)writeAll;

@end
