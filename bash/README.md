`Argumets order:` <full_directory_name> <type_1> <type_2> <archive_name>
`Example:` /home/user/Desktop/mydir cpp py archive.tar
`Commands used in code:`
find <dir_1> -path <dir_2> -prune -o ` - Seek in <dir_2> without entering <dir_2>`
-exec cp `- Runs cp for each found object`
--backup=numbered `- Adds symbol ~ and a number to a file with already occured name`
2>/dev/null 1>/dev/null `- Redirecting stderr and stdout beyound terminal`
