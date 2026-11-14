# Push_swap

## Description

Push_swap est un projet de tri algorithmique : à partir d'une pile d'entiers, le programme doit afficher la séquence d'opérations la plus courte possible pour trier la pile A dans l'ordre croissant (le plus petit au sommet), en utilisant uniquement deux piles (A et B) et un ensemble limité de 11 opérations.

## Opérations autorisées


| Opération | Description |
|-----------|-------------|
| `sa` | Swap les 2 premiers éléments de la pile A |
| `sb` | Swap les 2 premiers éléments de la pile B |
| `ss` | `sa` et `sb` simultanément |
| `pa` | Prend la tête de B et la met en tête de A |
| `pb` | Prend la tête de A et la met en tête de B |
| `ra` | Rotate A : le premier élément devient le dernier |
| `rb` | Rotate B : le premier élément devient le dernier |
| `rr` | `ra` et `rb` simultanément |
| `rra` | Reverse rotate A : le dernier élément devient le premier |
| `rrb` | Reverse rotate B : le dernier élément devient le premier |
| `rrr` | `rra` et `rrb` simultanément |

Chaque opération exécutée est affichée sur stdout et dans le bench mode>

 ---

## Algorithmes

### Mesure du désordre (disorder)

Avant tout tri, le programme calcule un ratio de désordre entre 0 et 1. Pour chaque paire (i, j) où i apparaît avant j dans la pile, si valeur[i] > valeur[j] c'est une inversion. Le disorder est le ratio inversions / total des paires.

- `0` = pile déjà triée
- `1` = pile complètement inversée

Il est affiché dans le bench mode et utilisé dans l'algorithme adaptive.

### 1. Simple — O(n²)

Recherche et extraction répétitive du nombre le plus petit de la pile A via `rotate_min`, sélection des opérations les plus optimales et push vers B. Quand A est vide, tous les éléments sont récupérés dans A dans l'ordre trié.

**Performance (500 nombres) :** ~32 000 opérations

### 2. Medium — O(n√n) — Tri par chunks

Divise les valeurs en chunks de taille √n. Pour chaque chunk, une valeur seuil est calculée (la chunk-ième plus petite valeur). Les éléments ≤ seuil sont poussés vers B immédiatement ; les autres sont décalée en attendant le prochain chunk les concernant.
Recherche et extraction répétitive du nombre le plus grand de la pile A via `rotate_max`, sélection des opérations les plus optimales et push vers A.

**Performance (500 nombres) :** ~8 200 opérations

### 3. Complex — O(n log n) — Radix Sort (LSD)

Normalise d'abord toutes les valeurs en rangs 0..n-1 (pour éviter les négatifs et les grandes valeurs en binaire). Puis trie bit par bit du moins significatif au plus significatif : si le bit courant est 0 → push vers B, si 1 → rotate A. Après chaque passe, tous les éléments sont récupérés depuis B vers A.

Nombre de passes = ⌊log₂(n)⌋

**Performance (500 nombres) :** ~6 784 opérations

### 4. Adaptive — Algorithme personnalisé

Sélectionne la meilleure stratégie selon le disorder mesuré :

| Disorder | Stratégie | Complexité |
|----------|-----------|------------|
| < 0.2 | `low_algo` : bubble sort en un seul passage (sans pile B) | O(n) |
| 0.2 ≤ d < 0.5 | `medium_algo` : tri par chunks | O(n√n) |
| ≥ 0.5 | `complex_algo_radix` : radix sort | O(n log n) |

**Justification des seuils :** Un disorder inférieur à 0.2 signifie très peu d'inversions — un seul passage correctif suffit en restant uniquement dans la pile A. Entre 0.2 et 0.5, le chunk sort est efficace. Au-dessus de 0.5, le radix sort avec son O(n log n) constant est optimal.


---
## Instructions

### Compilation

```bash
cd libft
make
cd ..
cc -Wall -Wextra -Werror -fPIE *.c libft/libft.a -o push_swap
```

### Utilisation

```bash
./push_swap [flags] <entiers>
```

**Flags disponibles :**

| Flag | Description |
|------|-------------|
| `--simple` | Force l'algorithme O(n²) |
| `--medium` | Force l'algorithme O(n√n) |
| `--complex` | Force l'algorithme O(n log n) |
| `--adaptive` | Force l'algorithme adaptatif (comportement par défaut) |
| `--bench` | Affiche les statistiques de benchmark sur stderr après le tri |


### Benchmarks de performance du projet

| Algorithme | 100 nombres | 500 nombres | Statut |
|------------|------------|-------------|--------|
| --simple | ~1 500 ops | ~32 000 ops | ✅ valide |
| --medium | ~800 ops | ~8 200 ops | ✅ bon |
| --complex | ~1 084 ops | ~6 784 ops | ✅ bon |
| --adaptive | ~812 ops | ~8 186 ops | ✅ bon |

Seuils du sujet : < 2 000 (100 nombres) / < 12 000 (500 nombres).

## Ressources

### Références
- [Man pages C](https://www.man7.org/linux/man-pages/) — référence des fonctions libc
- [cppreference.com](https://en.cppreference.com/w/c) — documentation C complète
- [Valgrind](https://valgrind.org/docs/manual/quick-start.html) — détection des fuites mémoire
- [La Norme 42](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf) — règles de codage
- [Radix Sort — Wikipedia](https://fr.wikipedia.org/wiki/Tri_par_base)
- [Les algorithmes de tri](https://interstices.info/les-algorithmes-de-tri/)

### Utilisation de l'IA

Claude (Anthropic) a été utilisé pour :

- **Comprendre les concepts** : complexité algorithmique, manipulation de listes chaînées
- **Conception de l'architecture** : choix des structures de données (t_bench, t_flags), organisation des fichiers, découpage des fonctions pour respecter la Norme
- **Débogage** : identification des segfaults (ft_lstclear avec del NULL, variables non initialisées), interprétation des erreurs Valgrind
- **Revue de code** : conformité norminette, vérification des signatures de fonctions, détection d'erreurs logiques
Tout le contenu généré par l'IA a été relu, compris et validé avant intégration. Les deux apprenants sont capables d'expliquer et de défendre chaque partie du code implémenté.
# Push_swap

## Description

Push_swap is a sorting algorithm project: given a stack of integers, the program must output the shortest possible sequence of operations to sort the stack in ascending order (smallest at top), using only two stacks (A and B) and a limited set of 11 operations.

This project introduces algorithmic complexity in a concrete way — the choice of algorithm makes a dramatic difference in performance.


## Algorithms

### Disorder metric

Before sorting, the program computes a disorder score between 0 and 1. For each pair (i, j) where i appears before j in the stack, if value[i] > value[j] it counts as an inversion. The disorder is the ratio of inversions to total pairs.

- `0` = already sorted
- `1` = fully reversed
### 1. Simple — O(n²)

Repeatedly extracts the minimum from stack A using `rotate_min` (which chooses the optimal rotation direction) and pushes it to stack B. When A is empty, all elements are pushed back to A in sorted order.

**Performance (500 numbers):** ~32,000 operations

### 2. Medium — O(n√n) — Chunk Sort

Divides values into chunks of size √n. For each chunk, a threshold value is computed (the chunk-th smallest value). Elements ≤ threshold are pushed to B immediately when encountered; others are rotated. The chunk size is computed without `sqrt()` using:

```c
i = 1;
while (i * i <= ft_lstsize(*stack_a))
    i++;
chunk = i - 1;
```

Recovery from B is done by always finding and rotating the maximum to the top before pushing to A.

**Performance (500 numbers):** ~8,200 operations

### 3. Complex — O(n log n) — Radix Sort (LSD)

First normalizes all values to ranks 0..n-1 (avoiding negative numbers and large values in binary). Then sorts bit by bit from least significant to most significant: if current bit is 0 → push to B, if 1 → rotate A. After each pass, all elements are pushed back from B to A.

Number of passes = ⌊log₂(n)⌋

**Performance (500 numbers):** ~6,784 operations

### 4. Adaptive — Custom design

Selects the best strategy based on the measured disorder:

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 0.2 | `low_algo`: single-pass bubble sort (no stack B needed) | O(n) |
| 0.2 ≤ d < 0.5 | `medium_algo`: chunk sort | O(n√n) |
| ≥ 0.5 | `complex_algo_radix`: radix sort | O(n log n) |

**Threshold rationale:** A disorder below 0.2 means very few inversions — a single corrective pass suffices. Between 0.2 and 0.5, chunk sort is efficient. Above 0.5, radix sort's consistent O(n log n) is optimal.

**Space complexity:** O(n) for both stacks combined.

## Instructions

### Compilation

```bash
make
```

### Usage

```bash
./push_swap [flags] <integers>
```

**Available flags:**

| Flag | Description |
|------|-------------|
| `--simple` | Forces O(n²) algorithm |
| `--medium` | Forces O(n√n) algorithm |
| `--complex` | Forces O(n log n) algorithm |
| `--adaptive` | Forces adaptive algorithm (default if no flag) |
| `--bench` | Displays benchmark statistics on stderr after sorting |


### Performance benchmarks

| Algorithm | 100 numbers | 500 numbers | Status |
|-----------|------------|-------------|--------|
| --simple | ~1,500 ops | ~32,000 ops | ✅ valid |
| --medium | ~800 ops | ~8,200 ops | ✅ good |
| --complex | ~1,084 ops | ~6,784 ops | ✅ good |
| --adaptive | ~812 ops | ~8,186 ops | ✅ good |

Subject requirements: <2000 (100 nums) / <12000 (500 nums) to pass, <700 / <5500 for excellent.

## Resources

### References

- [Big-O Notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Sorting Algorithms Visualizer](https://visualgo.net/en/sorting)
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- Donald Knuth, *The Art of Computer Programming*, Vol. 3: Sorting and Searching
### AI usage

Claude (Anthropic) was used throughout this project for:

- **Understanding concepts**: Big-O notation, algorithmic complexity, linked list manipulation
- **Architecture design**: deciding on data structures (t_bench, t_flags), file organization, function splitting to comply with the Norm
- **Debugging**: identifying segfaults (ft_lstclear with NULL del function, uninitialized variables), valgrind error interpretation
- **Code review**: norminette compliance, checking function signatures, spotting logical errors
- **Documentation**: generating this README and the HTML technical documentation
All AI-generated content was reviewed, understood, and validated before integration. Both learners can explain and defend every part of the implemented code.

## Contributors

| Login | Contributions |
|-------|--------------|
| mde-nas | simple_algo, sort_five, complex_algo (radix sort), disorder_metric, check functions, Makefile |
| chlepain | 11 stack operations, medium_algo (chunk sort), adaptive_algo, low_algo, benchmark mode, main/flags parsing, documentation |
