#include "framework/AssetManager.h"



namespace FromHeLL
{
	unique<AssetManager> AssetManager::m_spAssetManager = nullptr;
	AssetManager::AssetManager()
		: m_sRootDirectory{}
	{

	}

	AssetManager::~AssetManager()
	{
	}
	AssetManager& AssetManager::GetAssetManager()
	{
		if (!m_spAssetManager)
		{
			// we have to initialize first, since only members can initialize the class, (Constructor is protected)
			// unique<AssetManager> and  std::make_unique<AssetManager>()  would work
			// but we want unique pointer, meaning heap data allocation
			// so unique<AssetManager>{new AssetManager}
			m_spAssetManager = std::move(unique<AssetManager>{new AssetManager}); 
		}

		return *m_spAssetManager;
	}
	shared<sf::Texture> AssetManager::LoadTexture(const String& sPath)
	{
		Dictionary<String, shared<sf::Texture>>::iterator m_pIter;
		m_pIter  = m_dLoadedTextureMap.find( sPath );
		if (  m_pIter != m_dLoadedTextureMap.end() )
		{
			return m_pIter->second;
		}
		shared<sf::Texture> newTexture{new sf::Texture};

		if (newTexture->loadFromFile( m_sRootDirectory + sPath))
		{
			m_dLoadedTextureMap[sPath] = newTexture;
			//m_dLoadedTextureMap.insert({ sPath, newTexture });
			return newTexture;
		}

		return shared<sf::Texture> {nullptr};
	}
	void AssetManager::SetAssetRootDirectory( const String& sDirectoryPath )
	{
		m_sRootDirectory = sDirectoryPath;
	}

	void AssetManager::CleanCycle()
	{
		return;
		//auto Dictionary<String, shared<sf::Texture>>::iterator
		for (auto pIter = m_dLoadedTextureMap.begin(); pIter != m_dLoadedTextureMap.end(); )
		{
			// if no one is holding the share pointer other than the m_dLoadedTextureMap
			if ( pIter->second.unique() )
			{
				LOG("Cleaning Texture : %s", pIter->first.c_str());
				pIter = m_dLoadedTextureMap.erase(pIter);
			}
			else
			{
				++pIter;
			}

		}
	}
}