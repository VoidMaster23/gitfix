    // AUTO-GENERATED BY THE UPDATER. DO NOT EDIT 
    // GIT VERSION AT THE TIME OF GENERATION: "2.49.0"

    #pragma once
    #include <string>
    #include <array>

    const std::string git_version{"2.49.0"};

    // All sub comands for git version 2.49.0
    constexpr std::array<std::string_view, 175> commands = {	"add",
	"am",
	"annotate",
	"apply",
	"archimport",
	"archive",
	"backfill",
	"bisect",
	"blame",
	"branch",
	"bugreport",
	"bundle",
	"cat-file",
	"check-attr",
	"check-ignore",
	"check-mailmap",
	"check-ref-format",
	"checkout",
	"checkout--worker",
	"checkout-index",
	"cherry",
	"cherry-pick",
	"citool",
	"clean",
	"clone",
	"column",
	"commit",
	"commit-graph",
	"commit-tree",
	"config",
	"count-objects",
	"credential",
	"credential-cache",
	"credential-cache--daemon",
	"credential-store",
	"cvsexportcommit",
	"cvsimport",
	"cvsserver",
	"daemon",
	"describe",
	"diagnose",
	"diff",
	"diff-files",
	"diff-index",
	"diff-tree",
	"difftool",
	"difftool--helper",
	"fast-export",
	"fast-import",
	"fetch",
	"fetch-pack",
	"filter-branch",
	"fmt-merge-msg",
	"for-each-ref",
	"for-each-repo",
	"format-patch",
	"fsck",
	"fsck-objects",
	"fsmonitor--daemon",
	"gc",
	"get-tar-commit-id",
	"grep",
	"gui",
	"gui--askpass",
	"hash-object",
	"help",
	"hook",
	"http-backend",
	"http-fetch",
	"http-push",
	"imap-send",
	"index-pack",
	"init",
	"init-db",
	"instaweb",
	"interpret-trailers",
	"log",
	"ls-files",
	"ls-remote",
	"ls-tree",
	"mailinfo",
	"mailsplit",
	"maintenance",
	"merge",
	"merge-base",
	"merge-file",
	"merge-index",
	"merge-octopus",
	"merge-one-file",
	"merge-ours",
	"merge-recursive",
	"merge-recursive-ours",
	"merge-recursive-theirs",
	"merge-resolve",
	"merge-subtree",
	"merge-tree",
	"mergetool",
	"mktag",
	"mktree",
	"multi-pack-index",
	"mv",
	"name-rev",
	"notes",
	"p4",
	"pack-objects",
	"pack-redundant",
	"pack-refs",
	"patch-id",
	"pickaxe",
	"prune",
	"prune-packed",
	"pull",
	"push",
	"quiltimport",
	"range-diff",
	"read-tree",
	"rebase",
	"receive-pack",
	"reflog",
	"refs",
	"remote",
	"remote-ext",
	"remote-fd",
	"remote-ftp",
	"remote-ftps",
	"remote-http",
	"remote-https",
	"repack",
	"replace",
	"replay",
	"request-pull",
	"rerere",
	"reset",
	"restore",
	"rev-list",
	"rev-parse",
	"revert",
	"rm",
	"send-email",
	"send-pack",
	"sh-i18n--envsubst",
	"shell",
	"shortlog",
	"show",
	"show-branch",
	"show-index",
	"show-ref",
	"sparse-checkout",
	"stage",
	"stash",
	"status",
	"stripspace",
	"submodule",
	"submodule--helper",
	"svn",
	"switch",
	"symbolic-ref",
	"tag",
	"unpack-file",
	"unpack-objects",
	"update-index",
	"update-ref",
	"update-server-info",
	"upload-archive",
	"upload-archive--writer",
	"upload-pack",
	"var",
	"verify-commit",
	"verify-pack",
	"verify-tag",
	"version",
	"web--browse",
	"whatchanged",
	"worktree",
	"write-tree",

        };
    
    // Some common flags that need quotes
    constexpr std::array<std::string_view, 12> flags_with_quotes =  {	"-m",
	"--message",
	"-F",
	"--file",
	"--author",
	"--date",
	"--grep",
	"--committer",
	"--since",
	"--until",
	"--repo",
	"--receive-pack",

        }; 
    
    