//
//  GameStorageBase.h
//  FTE
//
//  Created by minseoi on 2022/02/19.
//

#ifndef GameStorageBase_h
#define GameStorageBase_h
/************************************************************/

#define READONLY_DATA(Type, Name) \
private: Type Name=0; \
public: static Type Get##Name(){return GetStorageInstance()->Name;} \

#define WRITEONLY_DATA(Type, Name) \
private: Type Name=0; \
public: static void Set##Name(Type value){GetStorageInstance()->Name = value;} \

#define READWRITE_DATA(Type, Name) \
private: Type Name=0; \
public: static Type Get##Name(){return GetStorageInstance()->Name;} \
        static void Set##Name(Type value){GetStorageInstance()->Name = value;} \

/************************************************************/
#endif /* GameStorageBase_h */
