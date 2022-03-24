set encoding=utf-8
set nobackup
set nowritebackup
set noswapfile
set clipboard+=unnamed
syntax on
set number
set nowrap
set statusline=%f%r%h%w%m%=%{&fileformat}\ %{&fileencoding}\ [%l,%c]
set laststatus=2
set tabstop=4
set shiftwidth=4
autocmd FileType python setl autoindent
autocmd FileType python setl smartindent cinwords=if,elif,else,for,while,def,class,try,except
autocmd FileType cpp setl cindent
autocmd FileType c setl cindent
set wrapscan
set hlsearch
set incsearch
let loaded_matchparen=1
nnoremap <ESC><ESC> :noh<CR>
if has('vim_starting')
	let &t_SI.="\e[6 q"
	let &t_EI.="\e[2 q"
endif
inoremap ( ()<Left>
inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap [ []<Left>
inoremap " ""<Left>
inoremap ' ''<Left>
colorscheme peachpuff
autocmd BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g`\"" | endif
set whichwrap=b,s,h,l,<,>,[,],~
if has('persistent_undo')
	set undodir=~/.vim/undo
	set undofile      
endif
let g:loaded_bracketed_paste=1
let &t_ti.="\<Esc>[?2004h"
let &t_te="\e[?2004l".&t_te
function! XTermPasteBegin(ret)
	set pastetoggle=<f29>
	set paste
	return a:ret
endfunction
execute "set <f28>=\<Esc>[200~"
execute "set <f29>=\<Esc>[201~"
map <expr> <f28> XTermPasteBegin("i")
inoremap <expr> <f28> XTermPasteBegin("")
vnoremap <expr> <f28> XTermPasteBegin("c")
cnoremap <f28> <nop>
cnoremap <f29> <nop>
