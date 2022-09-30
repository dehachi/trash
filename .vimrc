set encoding=utf-8
set nobackup
set nowritebackup
set noswapfile
set clipboard+=unnamed
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
set incsearch
nnoremap <ESC><ESC> :noh<CR>
inoremap ( ()<Left>
inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap [ []<Left>
inoremap " ""<Left>
inoremap ' ''<Left>
set whichwrap=b,s,h,l,<,>,[,],~
if has('persistent_undo')
	set undodir=~/.vim/undo
	set undofile      
endif
autocmd BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g`\"" | endif
syntax on
colorscheme peachpuff
if has('vim_starting')
	let &t_SI.="\e[6 q"
	let &t_EI.="\e[2 q"
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
set scrolloff=20
set list
set listchars=tab:\|\ 
set completeopt=menuone,noinsert
inoremap <expr><CR>  pumvisible() ? "<C-y>" : "<CR>"
inoremap <expr><C-n> pumvisible() ? "<Down>" : "<C-n>"
inoremap <expr><C-p> pumvisible() ? "<Up>" : "<C-p>"
function! Rep(...) abort
	if a:0 == 2
		execute "%s/\\<"..a:1.."\\>".."/"..a:2.."/g"
	elseif a:0 == 1
		execute "%s/\\<"..a:1.."\\>".."//g"
	end
endfunction
command! -nargs=+ Rep call Rep(<f-args>)
