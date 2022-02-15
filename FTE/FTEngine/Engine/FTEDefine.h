//
//  FTEDefine.h
//  FTE
//
//  Created by minseoi on 2022/02/16.
//

#ifndef FTEDefine_h
#define FTEDefine_h
/************************************************************/

#define DECLARE_FTE_OBJECT(thisClass, parentClass) \
    friend GameMaster; \
    typedef parentClass Super;\
protected: \
    thisClass(){} \


/************************************************************/
#endif /* FTEDefine_h */
