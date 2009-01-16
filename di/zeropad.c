/* $Xorg: zeropad.c,v 1.4 2001/02/09 02:05:32 xorgcvs Exp $ */

/*

Copyright 1996, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall
not be used in advertising or otherwise to promote the sale, use or
other dealings in this Software without prior written authorization
from The Open Group.

*/

/*
 * This module handles zeroing out unused pad bytes in X requests.
 * This will hopefully improve both stream and delta compression,
 * since we are removing the random values in pad bytes.
 */

#include <X11/Xproto.h>
#include "lbx.h"
#include "lbxext.h"

static void
ZeroEmptyReq(void *_req)
{
    xReq *req = _req;
    req->data = 0;
}

#define ZeroGetInputFocusReq ZeroEmptyReq
#define ZeroGetFontPathReq ZeroEmptyReq
#define ZeroGetKeyboardControlReq ZeroEmptyReq
#define ZeroGetPointerControlReq ZeroEmptyReq
#define ZeroGetPointerMappingReq ZeroEmptyReq
#define ZeroGetScreenSaverReq ZeroEmptyReq
#define ZeroGrabServerReq ZeroEmptyReq
#define ZeroListExtensionsReq ZeroEmptyReq
#define ZeroNoOperationReq ZeroEmptyReq
#define ZeroGetModifierMappingReq ZeroEmptyReq
#define ZeroQueryKeymapReq ZeroEmptyReq
#define ZeroUngrabServerReq ZeroEmptyReq


static void
ZeroResourceReq(void *_req)
{
    xResourceReq *req = _req;
    req->pad = 0;
}

#define ZeroFreePixmapReq ZeroResourceReq
#define ZeroGetAtomNameReq ZeroResourceReq
#define ZeroDestroySubwindowsReq ZeroResourceReq
#define ZeroDestroyWindowReq ZeroResourceReq
#define ZeroCloseFontReq ZeroResourceReq
#define ZeroQueryFontReq ZeroResourceReq
#define ZeroFreeCursorReq ZeroResourceReq
#define ZeroFreeGCReq ZeroResourceReq
#define ZeroGetGeometryReq ZeroResourceReq
#define ZeroGetSelectionOwnerReq ZeroResourceReq
#define ZeroGetWindowAttributesReq ZeroResourceReq
#define ZeroInstallColormapReq ZeroResourceReq
#define ZeroListInstalledColormapsReq ZeroResourceReq
#define ZeroListPropertiesReq ZeroResourceReq
#define ZeroMapSubwindowsReq ZeroResourceReq
#define ZeroMapWindowReq ZeroResourceReq
#define ZeroQueryPointerReq ZeroResourceReq
#define ZeroQueryTreeReq ZeroResourceReq
#define ZeroUngrabKeyboardReq ZeroResourceReq
#define ZeroUngrabPointerReq ZeroResourceReq
#define ZeroUninstallColormapReq ZeroResourceReq
#define ZeroUnmapSubwindowsReq ZeroResourceReq
#define ZeroUnmapWindowReq ZeroResourceReq
#define ZeroKillClientReq ZeroResourceReq
#define ZeroFreeColormapReq ZeroResourceReq


static void
ZeroChangeWindowAttributesReq(void *_req)
{
    xChangeWindowAttributesReq *req = _req;
    req->pad = 0;
}

static void
ZeroReparentWindowReq(void *_req)
{
    xReparentWindowReq *req = _req;
    req->pad = 0;
}

static void
ZeroConfigureWindowReq(void *_req)
{
    xConfigureWindowReq *req = _req;
    req->pad = 0;
    req->pad2 = 0;
}

static void
ZeroInternAtomReq(void *_req)
{
    xInternAtomReq *req = _req;
    req->pad = 0;
}

static void
ZeroChangePropertyReq(void *_req)
{
    xChangePropertyReq *req = _req;
    req->pad[0] = 0;
    req->pad[1] = 0;
    req->pad[2] = 0;
}

static void
ZeroDeletePropertyReq(void *_req)
{
    xDeletePropertyReq *req = _req;
    req->pad = 0;
}

static void
ZeroSetSelectionOwnerReq(void *_req)
{
    xSetSelectionOwnerReq *req = _req;
    req->pad = 0;
}

static void
ZeroConvertSelectionReq(void *_req)
{
    xConvertSelectionReq *req = _req;
    req->pad = 0;
}

static void
ZeroGrabButtonReq(void *_req)
{
    xGrabButtonReq *req = _req;
    req->pad = 0;
}

static void
ZeroUngrabButtonReq(void *_req)
{
    xUngrabButtonReq *req = _req;
    req->pad = 0;
}

static void
ZeroChangeActivePointerGrabReq(void *_req)
{
    xChangeActivePointerGrabReq *req = _req;
    req->pad = 0;
    req->pad2 = 0;
}

static void
ZeroGrabKeyboardReq(void *_req)
{
    xGrabKeyboardReq *req = _req;
    req->pad = 0;
}

static void
ZeroGrabKeyReq(void *_req)
{
    xGrabKeyReq *req = _req;
    req->pad1 = 0;
    req->pad2 = 0;
    req->pad3  = 0;
}

static void
ZeroUngrabKeyReq(void *_req)
{
    xUngrabKeyReq *req = _req;
    req->pad = 0;
}

static void
ZeroGetMotionEventsReq(void *_req)
{
    xGetMotionEventsReq *req = _req;
    req->pad = 0;
}

static void
ZeroTranslateCoordsReq(void *_req)
{
    xTranslateCoordsReq *req = _req;
    req->pad = 0;
}

static void
ZeroWarpPointerReq(void *_req)
{
    xWarpPointerReq *req = _req;
    req->pad = 0;
}

static void
ZeroOpenFontReq(void *_req)
{
    xOpenFontReq *req = _req;
    req->pad = 0;
    req->pad1 = 0;
    req->pad2 = 0;
}

static void
ZeroListFontsReq(void *_req)
{
    xListFontsReq *req = _req;
    req->pad = 0;
}

#define ZeroListFontsWithInfoReq ZeroListFontsReq

static void
ZeroSetFontPathReq(void *_req)
{
    xSetFontPathReq *req = _req;
    req->pad = 0;
    req->pad1 = 0;
    req->pad2 = 0;
}

static void
ZeroCreateGCReq(void *_req)
{
    xCreateGCReq *req = _req;
    req->pad = 0;
}

static void
ZeroChangeGCReq(void *_req)
{
    xChangeGCReq *req = _req;
    req->pad = 0;
}    

static void
ZeroCopyGCReq(void *_req)
{
    xCopyGCReq *req = _req;
    req->pad = 0;
}    

static void
ZeroSetDashesReq(void *_req)
{
    xSetDashesReq *req = _req;
    req->pad = 0;
}    

static void
ZeroCopyAreaReq(void *_req)
{
    xCopyAreaReq *req = _req;
    req->pad = 0;
}    

static void
ZeroCopyPlaneReq(void *_req)
{
    xCopyPlaneReq *req = _req;
    req->pad = 0;
}    

static void
ZeroPolySegmentReq(void *_req)
{
    xPolySegmentReq *req = _req;
    req->pad = 0;
}    

#define ZeroPolyArcReq ZeroPolySegmentReq
#define ZeroPolyRectangleReq ZeroPolySegmentReq
#define ZeroPolyFillRectangleReq ZeroPolySegmentReq
#define ZeroPolyFillArcReq ZeroPolySegmentReq

static void
ZeroFillPolyReq(void *_req)
{
    xFillPolyReq *req = _req;
    req->pad = 0;
    req->pad1 = 0;
}    

static void
ZeroPutImageReq(void *_req)
{
    xPutImageReq *req = _req;
    req->pad = 0;
}    

static void
ZeroPolyTextReq(void *_req)
{
    xPolyTextReq *req = _req;
    req->pad = 0;
}    

#define ZeroPolyText8Req ZeroPolyTextReq
#define ZeroPolyText16Req ZeroPolyTextReq

static void
ZeroCopyColormapAndFreeReq(void *_req)
{
    xCopyColormapAndFreeReq *req = _req;
    req->pad = 0;
}    

static void
ZeroAllocColorReq(void *_req)
{
    xAllocColorReq *req = _req;
    req->pad = 0;
    req->pad2 = 0;
}    

static void
ZeroAllocNamedColorReq(void *_req)
{
    xAllocNamedColorReq *req = _req;
    req->pad = 0;
    req->pad1 = 0;
    req->pad2 = 0;
}    

static void
ZeroFreeColorsReq(void *_req)
{
    xFreeColorsReq *req = _req;
    req->pad = 0;
}    

static void
ZeroStoreColorsReq(void *_req)
{
    xStoreColorsReq *req = _req;
    req->pad = 0;
}    

static void
ZeroStoreNamedColorReq(void *_req)
{
    xStoreNamedColorReq *req = _req;
    req->pad1 = 0;
    req->pad2 = 0;
}

static void
ZeroQueryColorsReq(void *_req)
{
    xQueryColorsReq *req = _req;
    req->pad = 0;
}    

static void
ZeroLookupColorReq(void *_req)
{
    xLookupColorReq *req = _req;
    req->pad = 0;
    req->pad1 = 0;
    req->pad2 = 0;
}    

static void
ZeroCreateCursorReq(void *_req)
{
    xCreateCursorReq *req = _req;
    req->pad = 0;
}    

static void
ZeroCreateGlyphCursorReq(void *_req)
{
    xCreateGlyphCursorReq *req = _req;
    req->pad = 0;
}    

static void
ZeroRecolorCursorReq(void *_req)
{
    xRecolorCursorReq *req = _req;
    req->pad = 0;
}    

static void
ZeroQueryExtensionReq(void *_req)
{
    xQueryExtensionReq *req = _req;
    req->pad = 0;
    req->pad1 = 0;
    req->pad2 = 0;
}

static void
ZeroGetKeyboardMappingReq(void *_req)
{
    xGetKeyboardMappingReq *req = _req;
    req->pad = 0;
    req->pad1 = 0;
}    

static void
ZeroChangeKeyboardMappingReq(void *_req)
{
    xChangeKeyboardMappingReq *req = _req;
    req->pad1 = 0;
}

static void
ZeroChangeKeyboardControlReq(void *_req)
{
    xChangeKeyboardControlReq *req = _req;
    req->pad = 0;
}    

static void
ZeroChangePointerControlReq(void *_req)
{
    xChangePointerControlReq *req = _req;
    req->pad = 0;
}    

static void
ZeroSetScreenSaverReq(void *_req)
{
    xSetScreenSaverReq *req = _req;
    req->pad = 0;
    req->pad2 = 0;
}    

static void
ZeroChangeHostsReq(void *_req)
{
    xChangeHostsReq *req = _req;
    req->pad = 0;
}    

static void
ZeroListHostsReq(void *_req)
{
    xListHostsReq *req = _req;
    req->pad = 0;
}

static void
ZeroRotatePropertiesReq(void *_req)
{
    xRotatePropertiesReq *req = _req;
    req->pad = 0;
}

void (*ZeroPadReqVector[128])(void *) =
{
    NULL,
    NULL, /* CreateWindowReq */
    ZeroChangeWindowAttributesReq,
    ZeroGetWindowAttributesReq,
    ZeroDestroyWindowReq,
    ZeroDestroySubwindowsReq,		/* 5 */
    NULL, /* ChangeSaveSetReq */
    ZeroReparentWindowReq,
    ZeroMapWindowReq,
    ZeroMapSubwindowsReq,
    ZeroUnmapWindowReq,			/* 10 */
    ZeroUnmapSubwindowsReq,
    ZeroConfigureWindowReq,
    NULL, /* CirculateWindowReq */
    ZeroGetGeometryReq,
    ZeroQueryTreeReq,			/* 15 */
    ZeroInternAtomReq,
    ZeroGetAtomNameReq,
    ZeroChangePropertyReq,
    ZeroDeletePropertyReq,
    NULL, /* GetPropertyReq */		/* 20 */
    ZeroListPropertiesReq,
    ZeroSetSelectionOwnerReq,
    ZeroGetSelectionOwnerReq,
    ZeroConvertSelectionReq,
    NULL, /* SendEventReq */		/* 25 */
    NULL, /* GrabPointerReq */
    ZeroUngrabPointerReq,
    ZeroGrabButtonReq,
    ZeroUngrabButtonReq,
    ZeroChangeActivePointerGrabReq,	/* 30 */
    ZeroGrabKeyboardReq,
    ZeroUngrabKeyboardReq,
    ZeroGrabKeyReq,
    ZeroUngrabKeyReq,
    NULL, /* AllowEventsReq */		/* 35 */
    ZeroGrabServerReq,
    ZeroUngrabServerReq,
    ZeroQueryPointerReq,
    ZeroGetMotionEventsReq,
    ZeroTranslateCoordsReq,		/* 40 */
    ZeroWarpPointerReq,
    NULL, /* SetInputFocusReq */
    ZeroGetInputFocusReq,
    ZeroQueryKeymapReq,
    ZeroOpenFontReq,			/* 45 */
    ZeroCloseFontReq,
    ZeroQueryFontReq,
    NULL, /* QueryTextExtentsReq */
    ZeroListFontsReq,
    ZeroListFontsWithInfoReq,		/* 50 */
    ZeroSetFontPathReq,
    ZeroGetFontPathReq,
    NULL, /* CreatePixmapReq */
    ZeroFreePixmapReq,
    ZeroCreateGCReq,			/* 55 */
    ZeroChangeGCReq,
    ZeroCopyGCReq,
    ZeroSetDashesReq,
    NULL, /* SetClipRectanglesReq */
    ZeroFreeGCReq,			/* 60 */
    NULL, /* ClearToBackgroundReq */
    ZeroCopyAreaReq,
    ZeroCopyPlaneReq,
    NULL, /* PolyPointReq */
    NULL, /* PolyLineReq */		/* 65 */
    ZeroPolySegmentReq,
    ZeroPolyRectangleReq,
    ZeroPolyArcReq,
    ZeroFillPolyReq,
    ZeroPolyFillRectangleReq,		/* 70 */
    ZeroPolyFillArcReq,
    ZeroPutImageReq,
    NULL, /* GetImageReq */
    ZeroPolyText8Req,
    ZeroPolyText16Req,			/* 75 */
    NULL, /* ImageText8Req */
    NULL, /* ImageText16Req */
    NULL, /* CreateColormapReq */
    ZeroFreeColormapReq,
    ZeroCopyColormapAndFreeReq,		/* 80 */
    ZeroInstallColormapReq,
    ZeroUninstallColormapReq,
    ZeroListInstalledColormapsReq,
    ZeroAllocColorReq,
    ZeroAllocNamedColorReq,		/* 85 */
    NULL, /* AllocColorCellsReq */
    NULL, /* AllocColorPlanesReq */
    ZeroFreeColorsReq,
    ZeroStoreColorsReq,
    ZeroStoreNamedColorReq,		/* 90 */
    ZeroQueryColorsReq,
    ZeroLookupColorReq,
    ZeroCreateCursorReq,
    ZeroCreateGlyphCursorReq,
    ZeroFreeCursorReq,			/* 95 */
    ZeroRecolorCursorReq,
    NULL, /* QueryBestSizeReq */
    ZeroQueryExtensionReq,
    ZeroListExtensionsReq,
    ZeroChangeKeyboardMappingReq,	/* 100 */
    ZeroGetKeyboardMappingReq,
    ZeroChangeKeyboardControlReq,
    ZeroGetKeyboardControlReq,
    NULL, /* BellReq */
    ZeroChangePointerControlReq,	/* 105 */
    ZeroGetPointerControlReq,
    ZeroSetScreenSaverReq,
    ZeroGetScreenSaverReq,
    ZeroChangeHostsReq,
    ZeroListHostsReq,			/* 110 */
    NULL, /* ChangeAccessControlReq */
    NULL, /* ChangeCloseDownModeReq */
    ZeroKillClientReq,
    ZeroRotatePropertiesReq,
    NULL, /* ForceScreenSaverReq */	/* 115 */
    NULL, /* SetPointerMappingReq */
    ZeroGetPointerMappingReq,
    NULL, /* SetModifierMappingReq */
    ZeroGetModifierMappingReq,
    NULL,				/* 120 */
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,				/* 125 */
    NULL,
    ZeroNoOperationReq
};
