​🌿 Simulateur d'Écosystème Dynamique (C++ / SDL3)
​📝 DESCRIPTION DU PROJET
​Ce projet est un simulateur d'écosystème virtuel en deux dimensions où des agents autonomes interagissent selon des règles biologiques simples. Le moteur utilise une architecture Orientée Objet (POO) stricte et la librairie SDL3 pour l'affichage graphique.
​Le but est d'observer les dynamiques de population (proies contre prédateurs) et les cycles de vie régis par l'énergie, la reproduction et la survie.
​🌹 Fonctionnalités Clés
​Déplacement Autonome : Les entités (Herbivores, Carnivores) se déplacent en appliquant des forces de direction.
​Cycles Biologiques : Système de recherche de nourriture, de fuite de prédateurs, de reproduction (coût énergétique) et de mort (faim ou vieillesse).
​Physique Simple : Gestion des forces, de la vitesse et maintien des agents dans les limites du monde simulé.
​Moteur de Jeu : Boucle principale à Pas de Temps Fixe (Fixed Time Step) pour des mises à jour logiques stables (60 FPS).
​Interface Graphique : Rendu en temps réel des agents et de la nourriture via SDL3.
​📒 ARCHITECTURE DU PROJET
​L'architecture sépare clairement le Cœur de la Logique (Core) de l'Abstraction Graphique (Graphics), permettant une grande modularité.
​1. Structure des Fichiersecosystem_simulator/
├── include/
│   ├── Core/
│   │   ├── Structs.hpp
│   │   ├── Entity.hpp
│   │   └── Ecosystem.hpp
│   └── Graphics/
│       ├── Window.hpp
│       └── Renderer.hpp
├── src/
│   ├── Core/
│   │   ├── Entity.cpp
│   │   └── Ecosystem.cpp
│   ├── Graphics/
│   │   ├── Window.cpp
│   │   └── Renderer.cpp
│   └── main.cpp
|------build.bat
├── assets/
│   └── (futures textures)
└── README.md
IMPLÉMENTATIONS ET LOGIQUE DES AGENTS
​Le comportement des agents est régi par des Steering Behaviors, des fonctions qui calculent un vecteur de force pour modifier la direction de l'entité.
Fonction Fichier Rôle Explication Détaillée
Vector2D SeekFood() Entity.cpp Recherche de Cible Calcule la direction de l'entité vers la source de nourriture la plus proche. Retourne un vecteur directionnel (à normaliser) qui, une fois appliqué, guide l'entité vers sa proie.
Vector2D AvoidPredators() Entity.cpp Évitement Calcule un vecteur de répulsion pour éloigner l'entité du prédateur le plus proche dans son champ de vision. Essentiel pour le comportement de fuite.
Vector2D StayInBounds() Entity.cpp Contrôle Limite Détecte si l'entité approche du bord de l'écran et applique une force opposée pour la ramener à l'intérieur de la fenêtre simulée.
void ApplyForce() Entity.cpp Moteur Physique Reçoit un vecteur force (résultant de Seek ou Avoid) et l'ajoute à l'accélération/vitesse de l'entité, modifiant ainsi son mouvement pour la prochaine image.
void AddEntity() Ecosystem.h Gestion de Population Ajoute dynamiquement une nouvelle entité (std::unique_ptr<Entity>) au conteneur principal de l'écosystème. Utilisé lors de la reproduction.
IMPLÉMENTATIONS ET LOGIQUE DES AGENTS
​Le comportement des agents est régi par des Steering Behaviors, des fonctions qui calculent un vecteur de force pour modifier la direction de l'entité.
Fonction Fichier Rôle Explication Détaillée
Vector2D SeekFood() Entity.cpp Recherche de Cible Calcule la direction de l'entité vers la source de nourriture la plus proche. Retourne un vecteur directionnel (à normaliser) qui, une fois appliqué, guide l'entité vers sa proie.
Vector2D AvoidPredators() Entity.cpp Évitement Calcule un vecteur de répulsion pour éloigner l'entité du prédateur le plus proche dans son champ de vision. Essentiel pour le comportement de fuite.
Vector2D StayInBounds() Entity.cpp Contrôle Limite Détecte si l'entité approche du bord de l'écran et applique une force opposée pour la ramener à l'intérieur de la fenêtre simulée.
void ApplyForce() Entity.cpp Moteur Physique Reçoit un vecteur force (résultant de Seek ou Avoid) et l'ajoute à l'accélération/vitesse de l'entité, modifiant ainsi son mouvement pour la prochaine image.
void AddEntity() Ecosystem.h Gestion de Population Ajoute dynamiquement une nouvelle entité (std::unique_ptr<Entity>) au conteneur principal de l'écosystème. Utilisé lors de la reproduction.
🛠 INSTALLATION ET COMPILATION
​1. Installation (Clonage)
​Le projet doit être cloné dans un dossier local (ici ecosystem)
git add  . 
git commit -m "Add base for Ecosysteme"
git push
Compilation (MinGW / g++)
​Pour la compilation, il est nécessaire de spécifier tous les fichiers source et les chemins d'accès aux fichiers d'en-tête, en plus des librairies SDL3.
​⚠ REMARQUE IMPORTANTE (Restriction) : Si vous avez dû modifier les chemins d'accès dans vos fichiers .cpp pour que la compilation fonctionne, cela indique que le compilateur ne trouvait pas les fichiers .h. L'utilisation correcte de l'option -I./include dans la commande g++ devrait résoudre ce problème de chemins relatifs.
​Utilisez  le script build.bat (Windows) qui contient le code suivant: g++ -std=c++17 -Iinclude -o ecosystem src/*.cpp src/Core/*.cpp src/Graphics/*.cpp -lSDL3
pour executer utilisez la commande
./ECOSYSTEM
 UTILISATION ET CONTRÔLES
​L'interaction avec la simulation se fait via les événements clavier gérés par la classe GameEngine.Touche Action Description
ESC Quitter Arrête la boucle de jeu.
ESPACE Pause/Reprise Met la logique de la simulation en pause (mIsPaused).
HAUT (↑) Accélérer le Temps Augmente le TimeScale (simulation plus rapide).
BAS (↓) Ralentir le Temps Diminue le TimeScale (simulation plus lente).
R Réinitialiser Réinitialise l'écosystème à la population initiale.
F Ajouter Nourriture Ajoute de nouvelles sources de nourriture statique (Food).REMERCIEMENTS
​Ce projet est un excellent exercice pour solidifier les notions de POO, d'architecture logicielle et de gestion des dépendances externes (SDL3). Il combine un travail intellectuel sur la simulation et un divertissement visuel grâce à l'interface graphique. Merci pour cet apprentissage enrichissant ! ❤❤
