#include "Core/Ecosystem.h"
#include <algorithm>
#include <iostream>

namespace Ecosystem {
namespace Core {

// 🏗 CONSTRUCTEUR
Ecosystem::Ecosystem(float width, float height, int maxEntities)
    : mWorldWidth(width), mWorldHeight(height), mMaxEntities(maxEntities),
      mDayCycle(0), mRandomGenerator(std::random_device{}())
{
    // Initialisation des statistiques
    mStats = {0, 0, 0, 0, 0, 0};
    std::cout << "🌍 Écosystème créé: " << width << "x" << height << std::endl;
}

// 🗑 DESTRUCTEUR
Ecosystem::~Ecosystem() {
    std::cout << "🌍 Écosystème détruit (" << mEntities.size() << " entités nettoyées)" << std::endl;
}

// ⚙️ INITIALISATION
void Ecosystem::Initialize(int initialHerbivores, int initialCarnivores, int initialPlants) {
    mEntities.clear();
    mFoodSources.clear();
    
    // Création des entités initiales
    for (int i = 0; i < initialHerbivores; ++i) {
        SpawnRandomEntity(EntityType::HERBIVORE);
    }
    
    for (int i = 0; i < initialCarnivores; ++i) {
        SpawnRandomEntity(EntityType::CARNIVORE);
    }
    
    for (int i = 0; i < initialPlants; ++i) {
        SpawnRandomEntity(EntityType::PLANT);
    }
    
    // Nourriture initiale
    SpawnFood(20);
    
    std::cout << "🌱 Écosystème initialisé avec " << mEntities.size() << " entités" << std::endl;
}

// 🔄 MISE À JOUR
void Ecosystem::Update(float deltaTime) {
    // Mise à jour de toutes les entités
    for (auto& entity : mEntities) {
        entity->Update(deltaTime);
    }
    
    // Gestion des comportements
    HandleEating();
    HandleReproduction();
    RemoveDeadEntities();
    HandlePlantGrowth(deltaTime);
    
    // Mise à jour des statistiques
    UpdateStatistics();
    mDayCycle++;
}

// 🍎 GÉNÉRATION DE NOURRITURE
void Ecosystem::SpawnFood(int count) {
    for (int i = 0; i < count; ++i) {
        if (mFoodSources.size() < 100) {  // Limite maximale de nourriture
            Vector2D position = GetRandomPosition();
            mFoodSources.emplace_back(position, 25.0f);
        }
    }
}

 
