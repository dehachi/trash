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
if has("autocmd")
	au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g`\"" | endif
endif
set whichwrap=b,s,h,l,<,>,[,],~
if has('persistent_undo')
	set undodir=~/.vim/undo
	set undofile      
endif
