#pragma once 
#include "framework/Core.h"
#include <SFML/Graphics.hpp>


namespace FromHeLL
{
	class AssetManager
	{
		public : 
			~AssetManager();
			static AssetManager& GetAssetManager();
			shared <sf::Texture> LoadTexture(const String& sPath);
			void SetAssetRootDirectory( const String& sDirectoryPath );
			void CleanCycle();
		protected :
			AssetManager();
			
		private :
			static unique<AssetManager> m_spAssetManager;
			Dictionary<String, shared<sf::Texture>> m_dLoadedTextureMap;
			String m_sRootDirectory;
	};

	// Note :
	//	when the Actor is done, the shared pointer btained through LoadTexture is destroyed but, the value in dictionary is not
	// possible ways to destroy it, 
	// use weak pointer
	// check if a value in the dictionary is still being used some other place if not destroy it.
}