#pragma once

#ifdef __APPLE__
    #include <Carbon/Carbon.h>
    #include <QStringList>

    #define CGSDefaultConnection _CGSDefaultConnection()

    typedef uint64_t CGSConnection;
    typedef uint64_t CGSSpace;

    typedef enum _CGSSpaceType {
        kCGSSpaceUser,
        kCGSSpaceFullscreen,
        kCGSSpaceSystem,
        kCGSSpaceUnknown
    } CGSSpaceType;

    typedef enum _CGSSpaceSelector {
        kCGSSpaceCurrent = 5,
        kCGSSpaceAll = 7
    } CGSSpaceSelector;

    extern "C" CFArrayRef CGSCopySpaces(const CGSConnection cid, CGSSpaceSelector type);

    extern "C" CFArrayRef CGSSpaceCopyOwners(const CGSConnection cid, CGSSpace space);

    extern "C" int CGSSpaceGetAbsoluteLevel(const CGSConnection cid, CGSSpace space);
    extern "C" void CGSSpaceSetAbsoluteLevel(const CGSConnection cid, CGSSpace space, int level);

    extern "C" int CGSSpaceGetCompatID(const CGSConnection cid, CGSSpace space);
    extern "C" void CGSSpaceSetCompatID(const CGSConnection cid, CGSSpace space, int compatID);

    extern "C" CGSSpaceType CGSSpaceGetType(const CGSConnection cid, CGSSpace space);
    extern "C" void CGSSpaceSetType(const CGSConnection cid, CGSSpace space, CGSSpaceType type);

    extern "C" CFStringRef CGSSpaceCopyName(const CGSConnection cid, CGSSpace space);
    extern "C" void CGSSpaceSetName(const CGSConnection cid, CGSSpace space, CFStringRef name);

    extern "C" CFArrayRef CGSSpaceCopyValues(const CGSConnection cid, CGSSpace space);
    extern "C" void CGSSpaceSetValues(const CGSConnection cid, CGSSpace space, CFArrayRef values);

    typedef uint64_t CGSManagedDisplay;

    extern CFArrayRef CGSCopyManagedDisplaySpaces(const CGSConnection cid);

    extern "C" bool CGSManagedDisplayIsAnimating(const CGSConnection cid, CGSManagedDisplay display);
    extern "C" void CGSManagedDisplaySetIsAnimating(const CGSConnection cid, CGSManagedDisplay display, bool isAnimating);

    extern "C" CGSSpace PKGManagedDisplayGetCurrentSpace(const CGSConnection cid, CGSManagedDisplay display);
    extern "C" void CGSManagedDisplaySetCurrentSpace(const CGSConnection cid, CGSManagedDisplay display, CGSSpace space);

    extern "C" CGSManagedDisplay kCGSPackagesMainDisplayIdentifier;

    extern "C" CGSConnection _CGSDefaultConnection(void);

    extern Q_DECL_EXPORT QStringList getSpaces();

#elif
    #error This library only works on MacOS.
#endif
