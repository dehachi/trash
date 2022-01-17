" dein.vim settings {{{
" install dir {{{
let s:dein_dir = expand('~/.cache/dein')
let s:dein_repo_dir = s:dein_dir . '/repos/github.com/Shougo/dein.vim'
" }}}

" dein installation check {{{
if &runtimepath !~# '/dein.vim'
  if !isdirectory(s:dein_repo_dir)
    execute '!git clone https://github.com/Shougo/dein.vim' s:dein_repo_dir
  endif
  execute 'set runtimepath^=' . s:dein_repo_dir
endif
" }}}

" begin settings {{{
if dein#load_state(s:dein_dir)
  call dein#begin(s:dein_dir)

  " .toml file
  let s:rc_dir = expand('~/.vim')
  if !isdirectory(s:rc_dir)
    call mkdir(s:rc_dir, 'p')
  endif
  let s:toml = s:rc_dir . '/dein.toml'

  " read toml and cache
  call dein#load_toml(s:toml, {'lazy': 0})

  " end settings
  call dein#end()
  call dein#save_state()
endif
" }}}

" plugin installation check {{{
if dein#check_install()
  call dein#install()
endif
" }}}

" plugin remove check {{{
let s:removed_plugins = dein#check_clean()
if len(s:removed_plugins) > 0
  call map(s:removed_plugins, "delete(v:val, 'rf')")
  call dein#recache_runtimepath()
endif
" }}}

set background=dark
set t_Co=256
let g:solarized_termcolors=256
let g:solarized_termtrans = 1
syntax on
colorscheme railscasts
set number
syntax on
autocmd FileType python setl autoindent
autocmd FileType python setl smartindent cinwords=if,elif,else,for,while,def,class,try,except
autocmd FileType cpp setl cindent
set whichwrap=b,s,h,l,<,>,[,],~
set tabstop=4
set shiftwidth=4
set nowrap
set encoding=utf-8
set nobackup
set scrolloff=255
augroup vimrcEx
	au BufRead * if line("'\"") > 0 && line("'\"") <= line("$") |
	\ exe "normal g'\"" | endif
augroup END
autocmd InsertEnter,InsertLeave * set cursorline!
highlight CursorLine term=none cterm=none ctermfg=none ctermbg=0
autocmd InsertEnter,InsertLeave * set cursorline!
set cursorline
autocmd InsertEnter,InsertLeave * set cursorcolumn!
highlight CursorColumn term=none cterm=none ctermfg=none ctermbg=0
autocmd InsertEnter,InsertLeave * set cursorcolumn!
set cursorcolumn
set clipboard+=unnamed
set noswapfile
set statusline=%f%r%h%w%m%=%{&fileformat}\ %{&fileencoding}\ [%l,%c]
set laststatus=2
""set list
""set listchars=tab:\|\ 
set wrapscan
set hlsearch
set incsearch
set completeopt=menuone,noinsert
nnoremap <ESC><ESC> :noh<CR>
if has('vim_starting')
	let &t_SI.="\e[6 q"
	let &t_EI.="\e[2 q"
endif
if has('persistent_undo')
  set undodir=~/.vim/undo
  set undofile                                                                                                                                   
endif
let g:netrw_use_errorwindow=0
let g:netrw_banner=0
let g:netrw_preview=1
let g:netrw_liststyle=0
let g:netrw_keepdir=0

set splitbelow
set splitright

let g:mainid=0
let g:termid=0
let g:term_disp=0
let g:filename=''
let g:lastfile=''
let g:menu_disp=0
let g:menuid=0

function! Term_Open()
	if g:term_disp==0
		silent execute "normal :terminal\<CR>"
		let g:term_disp=1
		let g:termid=win_getid()
	else
		silent execute "normal :call win_gotoid(g:termid)\<CR>"
	endif
endfunction

function! Term_Close()
	if g:term_disp==1
		silent execute "normal :call win_gotoid(g:termid)\<CR>"
		silent execute "normal :q!\<CR>\<Left>"
		let g:term_disp=0
	endif
endfunction

function! Term_Select()
execute "normal :echo ''\<CR>"
if g:term_disp==0
silent execute "normal :call Term_Open()\<CR>"
else
silent execute "normal :call Term_Close()\<CR>"
endif
endfunction

function! Term_Row_Up()
	execute "normal :echo ''\<CR>"
	let l:posid=win_getid()
	if g:term_disp==1
		silent execute "normal :call win_gotoid(g:termid)\<CR>"
		silent execute "normal \<C-w>+"
	endif
	silent execute "normal :call win_gotoid(l:posid)\<CR>"
endfunction

function! Term_Row_Down()
	execute "normal :echo ''\<CR>"
	let l:posid=win_getid()
	if g:term_disp==1
		silent execute "normal :call win_gotoid(g:termid)\<CR>"
		silent execute "normal \<C-w>-"
	endif
	silent execute "normal :call win_gotoid(l:posid)\<CR>"
endfunction


function! Menu_Open()
	let g:lastfile=expand("%:p")
	execute "normal :echo ''\<CR>"
	silent execute "normal :w\<CR>:e .\<CR>"
endfunction

function! Menu_Close()
	execute "normal :echo ''\<CR>"
	execute "normal :e ".g:lastfile."\<CR>"
endfunction

function! Menu_Select()
	execute "normal :echo ''\<CR>"
	if &filetype=='netrw'
		silent execute "normal :call Menu_Close()\<CR>"
	else
		silent execute "normal :call Menu_Open()\<CR>"
	endif
endfunction

function! WinEnter_Setting()
	colorscheme railscasts
	if win_id2tabwin(g:mainid)==[0,0]
		silent execute "normal :call win_gotoid(g:termid)\<CR>"
		silent execute "normal :q!\<CR>"
	elseif win_id2tabwin(g:termid)==[0,0]
		let g:term_disp=0
		silent execute "normal :set laststatus=2\<CR>"	
	endif
endfunction

function! Vim_Init()
	let g:mainid=win_getid()
	let g:filename=expand("%:t")
	silent execute "normal :call Term_Open()\<CR>"
	silent execute "normal 15\<C-w>_\<CR>"
	silent execute "normal :call win_gotoid(g:mainid)\<CR>"
endfunction

autocmd VimEnter * call Vim_Init()
autocmd WinEnter * call WinEnter_Setting()


inoremap <expr><CR>  pumvisible() ? "<C-y>" : "<CR>"
inoremap ( ()<Left>
inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap [ []<Left>
inoremap " ""<Left>
inoremap ' ''<Left>
nnoremap <C-b> :call Menu_Select()<CR>
nnoremap <C-t> :call Term_Select()<CR>
tnoremap <C-t> <C-w>:call Term_Select()<CR>
nnoremap <C-Up> <ESC>:call Term_Row_Up()<CR>
nnoremap <C-Down> :call Term_Row_Down()<CR>
tnoremap <C-Up> <C-w>:call Term_Row_Up()<CR>
tnoremap <C-Down> <C-w>:call Term_Row_Down()<CR>
