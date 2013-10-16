/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "ODK.h"


// For MIPs (and WP8) platform we do not have asm code for stack switching 
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*OuyaController_startOfFrame_t)();
typedef       bool(*OuyaController_selectControllerByPlayer_t)(int playerNum);
typedef       bool(*OuyaController_selectControllerByDeviceID_t)(int deviceID);
typedef        int(*OuyaController_getAxisValue_t)(int axis);
typedef       bool(*OuyaController_getButton_t)(int button);
typedef       bool(*OuyaController_buttonPressedThisFrame_t)(int button);
typedef       bool(*OuyaController_buttonReleasedThisFrame_t)(int button);
typedef       bool(*OuyaController_buttonChangedThisFrame_t)(int button);
typedef        int(*OuyaController_getPlayerNum_t)();
typedef       void(*OuyaPlugin_asyncSetDeveloperId_t)(const char* developerId);
typedef       void(*OuyaPlugin_asyncOuyaFetchGamerUUID_t)(CallbacksFetchGamerUUID* callbacksFetchGamerUUID);

/**
 * struct that gets filled in by ODKRegister
 */
typedef struct ODKFuncs
{
    OuyaController_startOfFrame_t m_OuyaController_startOfFrame;
    OuyaController_selectControllerByPlayer_t m_OuyaController_selectControllerByPlayer;
    OuyaController_selectControllerByDeviceID_t m_OuyaController_selectControllerByDeviceID;
    OuyaController_getAxisValue_t m_OuyaController_getAxisValue;
    OuyaController_getButton_t m_OuyaController_getButton;
    OuyaController_buttonPressedThisFrame_t m_OuyaController_buttonPressedThisFrame;
    OuyaController_buttonReleasedThisFrame_t m_OuyaController_buttonReleasedThisFrame;
    OuyaController_buttonChangedThisFrame_t m_OuyaController_buttonChangedThisFrame;
    OuyaController_getPlayerNum_t m_OuyaController_getPlayerNum;
    OuyaPlugin_asyncSetDeveloperId_t m_OuyaPlugin_asyncSetDeveloperId;
    OuyaPlugin_asyncOuyaFetchGamerUUID_t m_OuyaPlugin_asyncOuyaFetchGamerUUID;
} ODKFuncs;

static ODKFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xb889863, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: ODK");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xb889863, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool ODKAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void OuyaController_startOfFrame()
{
    IwTrace(ODK_VERBOSE, ("calling ODK[0] func: OuyaController_startOfFrame"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaController_startOfFrame();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

bool OuyaController_selectControllerByPlayer(int playerNum)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[1] func: OuyaController_selectControllerByPlayer"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_OuyaController_selectControllerByPlayer(playerNum);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool OuyaController_selectControllerByDeviceID(int deviceID)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[2] func: OuyaController_selectControllerByDeviceID"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_OuyaController_selectControllerByDeviceID(deviceID);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

int OuyaController_getAxisValue(int axis)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[3] func: OuyaController_getAxisValue"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_OuyaController_getAxisValue(axis);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool OuyaController_getButton(int button)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[4] func: OuyaController_getButton"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_OuyaController_getButton(button);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool OuyaController_buttonPressedThisFrame(int button)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[5] func: OuyaController_buttonPressedThisFrame"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_OuyaController_buttonPressedThisFrame(button);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool OuyaController_buttonReleasedThisFrame(int button)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[6] func: OuyaController_buttonReleasedThisFrame"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_OuyaController_buttonReleasedThisFrame(button);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool OuyaController_buttonChangedThisFrame(int button)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[7] func: OuyaController_buttonChangedThisFrame"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_OuyaController_buttonChangedThisFrame(button);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

int OuyaController_getPlayerNum()
{
    IwTrace(ODK_VERBOSE, ("calling ODK[8] func: OuyaController_getPlayerNum"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_OuyaController_getPlayerNum();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void OuyaPlugin_asyncSetDeveloperId(const char* developerId)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[9] func: OuyaPlugin_asyncSetDeveloperId"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_asyncSetDeveloperId(developerId);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void OuyaPlugin_asyncOuyaFetchGamerUUID(CallbacksFetchGamerUUID* callbacksFetchGamerUUID)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[10] func: OuyaPlugin_asyncOuyaFetchGamerUUID"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_asyncOuyaFetchGamerUUID(callbacksFetchGamerUUID);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
