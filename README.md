# 42 School — Engineering Portfolio

**Umberto Ponci · 42 Berlin · [GitHub](https://github.com/derealthink)**

My 42 School projects in one repository: from C libraries and Unix processes to graphics, containers and a collaborative web application. Every project contains its actual source files and its own build instructions. Team credits and existing license notices are preserved.

## Start here

- **[SyncText](projects/ft_transcendence)** — a team-built, self-hosted collaborative editor with real-time editing, accounts, document sharing and PostgreSQL persistence. See its README for contributor responsibilities.
- **[Minishell](projects/Minishell)** — a team-built Unix shell covering parsing, pipelines, redirections, builtins and signals.
- **[cub3D](projects/cub3d)** — a team-built raycasting renderer with textured walls and map validation.
- **[Inception](projects/inception)** — a Docker Compose stack connecting NGINX, WordPress/PHP-FPM and MariaDB.

## All projects

| Project | Technology | Engineering focus |
| --- | --- | --- |
| [Libft](projects/libft) | C | Strings, memory, allocation and reusable library design |
| [ft_printf](projects/ft_printf) | C | Variadic arguments, formatting and static libraries |
| [Get Next Line](projects/get_next_line) | C | Buffered I/O, file descriptors and persistent state |
| [Push Swap](projects/push_swap) | C | Stack operations, sorting and move-cost calculation |
| [Pipex](projects/pipex) | C / POSIX | Processes, pipes, redirections and command execution |
| [Philosophers](projects/philosophers-42) | C / pthreads | Threads, mutexes and concurrent lifecycle monitoring |
| [Minishell](projects/Minishell) | C / POSIX | Shell parsing, pipelines, builtins and signals |
| [cub3D](projects/cub3d) | C / MiniLibX | Raycasting, texture rendering and map validation |
| [C++ Modules](projects/Cpp) | C++ | Object-oriented programming, templates and STL exercises |
| [Inception](projects/inception) | Docker / NGINX / MariaDB | Container orchestration, TLS and persistent services |
| [SyncText · ft_transcendence](projects/ft_transcendence) | TypeScript / Next.js / PostgreSQL | Team-built collaborative editor with real-time document editing |

## Clone and explore

```sh
git clone https://github.com/derealthink/42-school.git
cd 42-school
```

All project files are included. No submodule setup is needed, including for Minishell's bundled library.

Build each project independently using its README. For example:

```sh
cd projects/philosophers-42
make
./philo 5 800 200 200 7
```

There is no shared build because projects use different languages and dependencies. The individual READMEs explain current limitations; inclusion does not assert a passing grade or production readiness.

## Repository organization

- `projects/` contains the 11 curriculum projects.
- [MIGRATION.md](MIGRATION.md) records source snapshots, bundled dependencies and omitted local artifacts.
- The separate [Acme](https://github.com/derealthink/Acme) agency website remains outside this collection.

The original project repositories retain their Git histories as archives. This collection imports their source snapshots; the original commit histories are not merged into this repository.
