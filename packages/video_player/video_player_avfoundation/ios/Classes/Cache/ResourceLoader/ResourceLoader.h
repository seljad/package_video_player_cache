// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import <Foundation/Foundation.h>
@import AVFoundation;
@protocol ResourceLoaderDelegate;

@interface ResourceLoader : NSObject

/*!
 This class acts as a resource loader for AVAssetResourceLoader and handles loading of media resource data from a specified URL.
 It supports caching and downloading of media data from the URL using a ContentCacheWorker and ContentDownloader.
 It uses a delegate pattern to notify the consumer of the resource loader about the progress and completion of resource loading.
 */

@property(nonatomic, strong, readonly) NSURL *url;
@property(nonatomic, weak) id<ResourceLoaderDelegate> delegate;

- (instancetype)initWithURL:(NSURL *)url;

- (void)addRequest:(AVAssetResourceLoadingRequest *)request;
- (void)removeRequest:(AVAssetResourceLoadingRequest *)request;

- (void)cancel;

@end

@protocol ResourceLoaderDelegate <NSObject>

- (void)resourceLoader:(ResourceLoader *)resourceLoader didFailWithError:(NSError *)error;

@end
