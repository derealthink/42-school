# Consolidation provenance

The projects were imported from public repositories owned by `derealthink`. The table records each imported Git tree. Original commit histories remain in the original repositories; this repository preserves the collection's history and adds source snapshots.

| Project | Source tree SHA |
| --- | --- |
| `libft` | `8347f3ef816bb0fb0466b010aad88cb2a9bd5ee7` |
| `ft_printf` | `7fae251352a0fbc54be5067ef753fd2b363564a2` |
| `get_next_line` | `a80c593018f0e40f1a839cc836dc39fd0c11e5c6` |
| `push_swap` | `42fdb7411c90b4052e33a9434f10da4c44113dc7` |
| `pipex` | `dfd6b0f2b9a299a2c17132bfac7ef0ec1ebaea6d` |
| `philosophers-42` | `6776e1da0e1dd39b5f719162594ca347aa1613c0` |
| `Minishell` | `888f279e436a277486d39a1e39cc8b54c2ae63b8` |
| `cub3d` | `d042657bf887a433652829077e6abc0bc5e3aafc` |
| `Cpp` | `f353479784aea2596b440ba29c127dff2e0cd8c6` |
| `inception` | `ec5a80dc9a2a96343c6b8b9070d12c769f74f976` |
| `ft_transcendence` | `5a9d65473382dad35ab92a470c071e1a9561f52f` |

Minishell's `libft/` dependency is vendored from the public repository `jqrsound/libft_extended` at commit `dd356979c8636efb5d531f43590b5451200132f3`. Its original files and notices are retained. Team authorship and project licenses remain in their respective folders; this collection does not add a blanket license.

Documentation navigation was updated for the consolidated layout. Runtime source files were not edited. Editor history/configuration, `.DS_Store`, checked-in object files, `a.out`, debug bundles and prebuilt `libft.a` were omitted. Inception's password files were replaced with `.example` placeholders; real local password files are ignored. Existing development and CI configuration stays inside each project folder.

## Validation

Verified 939 retained original files byte-for-byte against downloaded source snapshots and checked that all 11 projects have READMEs. No Git submodule entries remain. Minishell's bundled library builds, but its shell build hits an existing Readline/`FILE` header-order issue on this Linux toolchain. Earlier C build checks passed for Libft, ft_printf, Get Next Line source files, Push Swap and Philosophers; Pipex has documented build blockers. Full application/runtime testing was not part of this source consolidation.
