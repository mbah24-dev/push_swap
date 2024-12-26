# 📦 Push_swap

<p align="center">
  <img src="https://github.com/mbah24-dev/mbah24-dev/blob/main/42_badges/push_swape.png" alt="push_swap 42 project badge"/>
</p>

Push_swap est un projet de l'école 42 qui consiste à trier une pile d'entiers en utilisant un ensemble d'instructions prédéfinies. L'objectif est d'écrire un programme efficace capable de résoudre ce problème avec un minimum de mouvements. 🚀

---

## 📝 Sujet

Le programme **Push_swap** prend en entrée une liste d'entiers (positifs ou négatifs) et génère une séquence d'instructions pour trier ces entiers en utilisant deux piles (`a` et `b`). Les instructions valides sont :

- `sa` : Échanger les deux premiers éléments de la pile `a`.
- `sb` : Échanger les deux premiers éléments de la pile `b`.
- `ss` : Effectuer `sa` et `sb` simultanément.
- `pa` : Pousser le premier élément de `b` sur `a`.
- `pb` : Pousser le premier élément de `a` sur `b`.
- `ra` : Faire tourner tous les éléments de `a` vers le haut.
- `rb` : Faire tourner tous les éléments de `b` vers le haut.
- `rr` : Effectuer `ra` et `rb` simultanément.
- `rra` : Faire tourner tous les éléments de `a` vers le bas.
- `rrb` : Faire tourner tous les éléments de `b` vers le bas.
- `rrr` : Effectuer `rra` et `rrb` simultanément.

---

## 📂 Structure du projet

```
📁 push_swap
├── 📄 Makefile         # Pour compiler le programme
├── 📁 data
└──   📄 README.md      # Documentation du projet
├── 📁 src/             # Contient le code source
├──    📁 app/          # Contient le code source de l'application
├──    main.c           #  Point d'entrée principal
├── 📁 inc              # Fichiers d'en-tête (.h)
└── 📄 README.md        # Documentation du projet
```

---

## ⚙️ Compilation

Pour compiler le programme, exécutez simplement la commande :

```bash
make
```

Cela génère un exécutable appelé `push_swap`.

---

## 🚀 Utilisation

Exemple d'utilisation :

```bash
./push_swap 4 3 2 1
```

Le programme retournera une série d'instructions qui, lorsqu'exécutées, trieront les nombres donnés.

---

## ✅ Fonctionnalités

- Vérifie la validité des entrées (nombres entiers, sans doublons).
- Trie les nombres en utilisant des algorithmes optimisés pour différents cas (petites ou grandes piles).
- Produit une sortie minimale pour le tri.

---

## 🛠️ Tests

Pour tester votre programme :

1. Compiler le projet avec `make`.
2. Lancer des tests avec des piles aléatoires :

```bash
ARG="4 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```

3. Vérifier le nombre de coups utilisés :

```bash
ARG="4 3 2 1"; ./push_swap $ARG | wc -l
```

---

## 🔍 Exigences du sujet

- Gérer les erreurs (valeurs non numériques, doublons, dépassement des limites d'un entier).
- Être efficace dans le nombre d'instructions générées.
- Fournir une solution correcte dans tous les cas.

---

## 🌟 Objectif pédagogique

- Comprendre et implémenter des algorithmes de tri.
- Optimiser des solutions pour réduire leur complexité.
- Manipuler des structures de données comme les piles.

---

## 📧 Contact

Pour toute question ou suggestion :

📩 [mbah@student.42lyon.fr](mailto:mbah@student.42lyon.fr)

---

## ⚠️ Note importante

🛑 **Évitez de copier et coller ce code sans comprendre comment il fonctionne !** Le but du projet est d'apprendre et de maîtriser les concepts, pas de tricher. Prenez le temps de lire et d'analyser le code pour en tirer le maximum d'apprentissage. Merci ! 💡

---

## 🏆 Bon courage !

Rendez votre programme aussi efficace et propre que possible. Que le tri soit avec vous ! ✨
