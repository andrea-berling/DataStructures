if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <F2> :wi
map  h
map <NL> j
map  k
map  l
map Q gq
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
map <M-Up> [s
map <M-Down> ]s
map <F12> 
map <S-F7> :make clean all
map <F7> :make
map <F6> :Dox
map <F5> :!ctags -R –c++-kinds=+p –fields=+iaS –extra=+q .
map <F4> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,
nmap <F2> :w
inoremap  u
map! { {o}O
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=indent,eol,start
set comments=sl:/*,mb:\ *,elx:\ */
set display=truncate
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set history=200
set incsearch
set langnoremap
set nolangremap
set mouse=a
set nrformats=bin,hex
set ruler
set scrolloff=5
set shiftwidth=4
set showcmd
set showmatch
set smartindent
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc,.png,.jpg
set tabstop=4
set tags=./tags,./TAGS,tags,TAGS,~/.vim/tags/cpp,~/.vim/tags/gl,~/.vim/tags/sdl,~/.vim/tags/qt4
set termencoding=utf-8
set textwidth=120
set ttimeout
set ttimeoutlen=100
set wildmenu
" vim: set ft=vim :
