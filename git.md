**Rebase** \
depuis la branch_a: `git rebase branch_b` \
re-applique les commits faits sur branch_a au sommet de branch_b \
montre pour chaque commit re-appliqué les conflits, et demande si on veut éditer le message -> non

**Rename** \
`git commit --amend -m "an updated commit message"` \
Change the name of the last commit \
`git rebase -i HEAD~n` \
Ouvre le panneau d'édition des n derniers commits \
Attention si merge dans ces n derniers commits ça déconne

**Create a branch on a exiting commit** \
`git branch <branchname> <sha1-of-commit>`

**Modify a given commit content** \
*If this commit is the last one*
- make the needed modifications, `add` them
- `git commit --amend --no-edit`
*If it's not the last*
- get the `sha1` of the commit (e.g. 34abc)
- `git rebase -i '34abc^'` (don't forget the ^)
- in the editor modify `pick` to `edit` in front of `34abc`
- save the file and exit, you're currently just after the commit
- make the needed modifications, `add` them
- `git commit --amend --no-edit`
- `git rebase --continue`
*If it's not the last and the modifs have already been made*
- add the modifications
- get the sha of the commit in which the modifications need to be add (abc34)
- `git commit --fixup=abc34`
- `git rebase -i --autosquash abc34~`

**Modify a given commit name** \
*If this commit is the last one*
- `git commit --amend`
*If it's not the last*
- if it's nth commit in the branch `git rebase -i HEAD~n`
- in the editor modify `pick` to `reword` in front of the commits to rename
- save the file and exit, rename in the editor appearing

**Stash specific files** \
`git stash push <path1> <path2>`

**Merge conflicts on binary files** \
To accept the incoming version \
`git checkout --theirs -- path/to/conflicted-file.txt` \
To keep its own version \
`git checkout --ours -- path/to/conflicted-file.txt` \

**3 folders structures** \
Working directory > files modified, can be tracked with git stash \
Staging index > files added \
Commits history >

**Git reset** \
When checkout only moves HEAD to another commit, \
reset also moves the branch pointer, so the commits \
after this pointer are forgotten

**Git reset --soft** \
git reset HEAD~n --soft \
unknit the n last commits, allow to reorganize them differently

**Git revert**
specific file
git checkout <commit_sha> -- <path>

**Git add interactive** \
`git add -p <file>` \
Then for each chunk :
- y: take modif
- n: don't take it
- s: split into smaller chunks

**Change commit pointed by branch**
git branch --force <branch_name> <commit_sha/branch_name>

**Submodule**
If problem:
`git submodule sync`
`git submodule update --init --recursive`