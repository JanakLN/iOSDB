//
//  iOSDB.h
//  iOSDB
//
//  Created by Süleyman Çalık on 12/29/10.
//  Copyright 2010 Süleyman Çalık All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "sqlite3.h"


@interface iOSDB : NSObject 
{
	sqlite3 * database;
	BOOL isDatabaseOpen;
}

/*
 
 */
+(BOOL)setupWithFileName:(NSString *)name
               extension:(NSString *)extension
                 version:(NSString *)version;


+(BOOL)isReady;

/**
 Supports simple select queries like:
 SELECT a , b FROM todos WHERE a = 1 AND b = 2
 
 If elements argument is nil or empty array:
 SELECT * FROM todos WHERE a = 1 AND b = 2
 */
+(NSArray *)selectFromTable:(NSString *)table
                   elements:(NSArray *)elements
                       keys:(NSDictionary *)keys;


/// Inserts element to table
//  elements must be key-value
//  Returns: id of element if successful or -1 if unsuccessful
+(NSInteger)insertToTable:(NSString *)tableName
                 elements:(NSDictionary *)elements;


+(BOOL)updateTable:(NSString *)tableName
    withControlKey:(NSDictionary *)controlKey
       andElements:(NSDictionary *)elements;


+(BOOL)deleteFromTable:(NSString *)table
        withControlKey:(NSString *)key
              andValue:(NSString *)value;

+(void)clearTable:(NSString *)table;

+(void)clearTables:(NSArray *)tables;

+(void)clearAllTables;

@end
