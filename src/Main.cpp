#include <irrlicht/irrlicht.h>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Irrlicht/Renderer.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

using namespace CEGUI;

int main() {

    IrrlichtDevice *device = createDevice(video::EDT_SOFTWARE, dimension2d<u32>(640, 480),
					  16, false, false, false, 0);
    CEGUI::IrrlichtRenderer &myRenderer =
	CEGUI::IrrlichtRenderer::bootstrapSystem(device, 0);

    if(!device)
	return 1;

    device->setWindowCaption(L"Irrlicht + CEGUI!");

    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();

    guienv->addStaticText(L"Hello World! This is CEGUI and Irrlicht!",
			  rect<s32>(10,10,260,22), true);

    smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

    

    while(device->run()) {

	driver->beginScene(true, true, SColor(255,100,101,140));

	smgr->drawAll();
	guienv->drawAll();

	driver->endScene();
    }

    device->drop();

    return 0;

}
