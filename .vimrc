"dein.vim
let s:dein_dir = expand('~/.cache/dein')
let s:dein_repo_dir = s:dein_dir . '/repos/github.com/Shougo/dein.vim'
if &runtimepath !~# '/dein.vim'
	if !isdirectory(s:dein_repo_dir)
		execute '!git clone https://github.com/Shougo/dein.vim' s:dein_repo_dir
	endif
	execute 'set runtimepath^=' . s:dein_repo_dir
endif
if dein#load_state(s:dein_dir)
	call dein#begin(s:dein_dir)
	let s:rc_dir = expand('~/.vim')
	if !isdirectory(s:rc_dir)
		call mkdir(s:rc_dir, 'p')
	endif
	let s:toml = s:rc_dir . '/dein.toml'
	call dein#load_toml(s:toml, {'lazy': 0})
	call dein#end()
	call dein#save_state()
endif
if dein#check_install()
	call dein#install()
endif
let s:removed_plugins = dein#check_clean()
if len(s:removed_plugins) > 0
	call map(s:removed_plugins, "delete(v:val, 'rf')")
	call dein#recache_runtimepath()
endif

"行番号の表示
set number
"インデント
autocmd FileType python setl autoindent
autocmd FileType python setl smartindent cinwords=if,elif,else,for,while,def,class,try,except
autocmd FileType cpp setl cindent
"左右のカーソル移動で行を跨いで移動
set whichwrap=b,s,h,l,<,>,[,],~
"カラースキームの設定"シンタックスハイライトを有効にする
syntax on
"tabを4文字分にする
set tabstop=4
"インデントを4文字分にする
set shiftwidth=4
colorscheme default
"テキストを折り返さない
set nowrap
"文字コードの設定
set encoding=utf-8
"バックアップファイルを作成しない
set nobackup
"画面端でのスクロールに余裕をもつ
set scrolloff=255
"カーソル位置を記憶
augroup vimrcEx
	au BufRead * if line("'\"") > 0 && line("'\"") <= line("$") |
	\ exe "normal g'\"" | endif
augroup END
"カーソル行をハイライト
autocmd InsertEnter,InsertLeave * set cursorline!
highlight CursorLine term=none cterm=none ctermfg=none ctermbg=0
autocmd InsertEnter,InsertLeave * set cursorline!
set cursorline
"カーソル列をハイライト
autocmd InsertEnter,InsertLeave * set cursorcolumn!
highlight CursorColumn term=none cterm=none ctermfg=none ctermbg=0
autocmd InsertEnter,InsertLeave * set cursorcolumn!
set cursorcolumn
"クリップボードと連携
set clipboard+=unnamed
"swapファイルを無効にする
set noswapfile
"ステータスライン
set statusline=%f%r%h%w%m%=%{&fileformat}\ %{&fileencoding}\ [%l,%c]
set laststatus=2
"インデント可視化
set list
set listchars=tab:\|\ 
"検索ワードをハイライト
set hlsearch
nnoremap <ESC><ESC> :noh<CR>
"カーソルの形
if has('vim_starting')
	let &t_SI.="\e[6 q"
	let &t_EI.="\e[2 q"
endif
"ターミナル
set splitbelow
inoremap <C-w> <ESC><C-w>
inoremap <C-t> <ESC>:term<CR>
nnoremap <C-t> :terminal<CR>
tnoremap <C-t> <C-w>:quit!<CR>
tnoremap <C-k> <C-\><C-n><C-w>+i
tnoremap <C-j> <C-\><C-n><C-w>-i
