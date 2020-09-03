
#ifdef __APPLE__

#include "RextEditorWindow.h"
#include <Cocoa/Cocoa.h>
#include <QApplication>


void RextEditorWindow::HideTitleBar(){
    NSView *nativeView = reinterpret_cast<NSView *>(this->winId());
    NSWindow* nativeWindow = [nativeView window];

    [nativeWindow setStyleMask:
        [nativeWindow styleMask] | NSWindowStyleMaskFullSizeContentView | NSWindowTitleHidden];
    [nativeWindow setShowsToolbarButton: NO];

    [nativeWindow setTitlebarAppearsTransparent:YES];
}

#endif