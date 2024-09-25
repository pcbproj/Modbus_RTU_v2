rem "comment string for commit must be entered in "" "

git add .
echo comment_string1
set /p comment_string=
echo .


git commit -m %comment_string%
git push

pause
