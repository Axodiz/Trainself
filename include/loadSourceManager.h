#ifndef LOADSOURCEMANAGER_H
#define LOADSOURCEMANAGER_H

#include <memory>
#include <core/AssetManager.h>

// load all assets
// return AssetManager with assets
std::shared_ptr<AssetManager> loadSourceManager();

#endif
