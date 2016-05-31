#include <iostream>
#include <CEGUI/CEGUI.h>

using namespace CEGUI;

int main(int argc, char *argv[]) {

    using namespace CEGUI;
    Window* myRoot = WindowManager::getSingleton().loadLayoutFromFile( "test.layout" );
    System::getSingleton().getDefaultGUIContext().setRootWindow( myRoot );

    return 0;

    /*
    WindowManager& wmgr = WindowManager::getSingleton();
    Window* myRoot = wmgr.createWindow( "DefaultWindow", "root" );
    System::getSingleton().getDefaultGUIContext().setRootWindow( myRoot );
    
    FrameWindow* fWnd = static_cast<FrameWindow*>(wmgr.createWindow( "TaharezLook/FrameWindow", "testWindow" ));
    
    myRoot->addChild( fWnd );

    // position a quarter of the way in from the top-left of parent.
    fWnd->setPosition( UVector2( UDim( 0.25f, 0.0f ), UDim( 0.25f, 0.0f ) ) );
    // set size to be half the size of the parent
    fWnd->setSize(USize(UDim( 0.5f, 0.0f), UDim( 0.5f, 0.0f)));
    
    fWnd->setText("Hello World!");

    return 0;    
    */
}
