#include <iostream>

#include "tinyxml2.h"

int main(){

	tinyxml2::XMLDocument doc;
    doc.LoadFile( "test.xml" );
    
    tinyxml2::XMLElement* configElement = doc.FirstChildElement( "Config" );

	tinyxml2::XMLElement* resourcesElement = configElement->FirstChildElement( "Resources" );
// Get Images
	tinyxml2::XMLElement* imagesElement = resourcesElement->FirstChildElement("ImageResources");
	const char* imagesPath = imagesElement->GetText();
    printf( "Image Resources Path: %s\n", imagesPath );
    
// Get Textures
	tinyxml2::XMLElement* texturesElement = resourcesElement->FirstChildElement("TextureResources");
	const char* texturesPath = texturesElement->GetText();
    printf( "Textures Resources Path: %s\n", texturesPath );
    
// Get Audio
	tinyxml2::XMLElement* audioElement = resourcesElement->FirstChildElement("AudioResources");
	const char* audioPath = audioElement->GetText();
    printf( "Audio Resources Path: %s\n", audioPath );
    
    
    
    
	return 0;
}