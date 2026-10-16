# 42 School — Engineering Portfolio

**Umberto Ponci · 42 Berlin · [GitHub](https://github.com/derealthink)**

A collection of my public 42 School projects: from C libraries and Unix processes to graphics, containers and a collaborative web application. Team projects retain their original authorship and contributor credits in their repositories.

## Start here

- **[SyncText](https://github.com/derealthink/ft_transcendence)** — a team-built, self-hosted collaborative editor with real-time editing, accounts, document sharing and PostgreSQL persistence. See its README for contributor responsibilities.
- **[Minishell](https://github.com/derealthink/Minishell)** — a team-built Unix shell covering parsing, pipelines, redirections, builtins and signals.
- **[cub3D](https://github.com/derealthink/cub3d)** — a team-built raycasting renderer with textured walls and map validation.
- **[Inception](https://github.com/derealthink/inception)** — a Docker Compose stack connecting NGINX, WordPress/PHP-FPM and MariaDB.

## All projects

| Project | Technology | Engineering focus | Source checkout |
| --- | --- | --- | --- |
| [Libft](https://github.com/derealthink/libft) | C | Strings, memory, allocation and reusable library design | [`libft/`](projects/libft) |
| [ft_printf](https://github.com/derealthink/ft_printf) | C | Variadic arguments, formatting and static libraries | [`ft_printf/`](projects/ft_printf) |
| [Get Next Line](https://github.com/derealthink/get_next_line) | C | Buffered I/O, file descriptors and persistent state | [`get_next_line/`](projects/get_next_line) |
| [Push Swap](https://github.com/derealthink/push_swap) | C | Stack operations, sorting and move-cost calculation | [`push_swap/`](projects/push_swap) |
| [Pipex](https://github.com/derealthink/pipex) | C / POSIX | Processes, pipes, redirections and command execution | [`pipex/`](projects/pipex) |
| [Philosophers](https://github.com/derealthink/philosophers-42) | C / pthreads | Threads, mutexes and concurrent lifecycle monitoring | [`philosophers-42/`](projects/philosophers-42) |
| [Minishell](https://github.com/derealthink/Minishell) | C / POSIX | Shell parsing, pipelines, builtins and signals | [`Minishell/`](projects/Minishell) |
| [cub3D](https://github.com/derealthink/cub3d) | C / MiniLibX | Raycasting, texture rendering and map validation | [`cub3d/`](projects/cub3d) |
| [C++ Modules](https://github.com/derealthink/Cpp) | C++ | Object-oriented programming, templates and STL exercises | [`Cpp/`](projects/Cpp) |
| [Inception](https://github.com/derealthink/inception) | Docker / NGINX / MariaDB | Container orchestration, TLS and persistent services | [`inception/`](projects/inception) |
| [SyncText · ft_transcendence](https://github.com/derealthink/ft_transcendence) | TypeScript / Next.js / PostgreSQL | Team-built collaborative editor with real-time document editing | [`ft_transcendence/`](projects/ft_transcendence) |

## Clone the collection

Each project is included as a Git submodule, preserving its original repository, history and build layout.

```sh
git clone --recurse-submodules https://github.com/derealthink/42-school.git
cd 42-school
```

Already cloned without submodules?

```sh
git submodule update --init --recursive
```

To fetch just one project:

```sh
git submodule update --init --recursive projects/philosophers-42
```

Build projects from their own directories using their READMEs. There is no shared build because the projects use different languages and dependencies. Submodules are pinned to specific commits; newer upstream changes require an explicit submodule update.

## About this collection

These repositories document curriculum work and practical learning. Inclusion does not assert a passing grade, completion of every exercise or production readiness. The individual READMEs describe usage and known limitations.

The separate [Acme](https://github.com/derealthink/Acme) agency website is outside this curriculum collection. Private repositories are not included.
