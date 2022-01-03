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


"グローバル変数はここにまとめておく
let cptarget='filename' "コンパイルするファイル名
let cperrorid=0 "コンパイルエラーを表示するウインドウID
let cpresult=0 "コンパイルが成功したか(0:失敗, 1:成功)
let cperror_display=0 "コンパイルエラーが表示されているか(0:されてない, 1:されてる)
let mainid=0 "メインスペースのウインドウID
let greeting_phrase='hello' "hello

"行番号の表示
set nu
augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set rnu
    autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END
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

"起動時挨拶
function! Greeting()
	let h = strftime("%H")
	if l:h<14400
		let g:greeting_phrase='Good evening'
	elseif l:h<36000
		let g:greeting_phrase='Good Morning'
	elseif l:h<64800
		let g:greeting_phrase='Good afternoon'
	else
		let g:greeting_phrase='Good evening'
	endif
	execute "normal :echo g:greeting_phrase.', Master.'\<CR>"
endfunction

"vim起動時にすること
function! Init_vim()
	let g:mainid = win_getid()
	execute "normal :call Greeting()\<CR>"
endfunction

autocmd VimEnter * call Init_vim()

"メインスペースに移動
function! Go_mainspace()
	silent execute "normal :call win_gotoid(g:mainid)\<CR>"
endfunction

"ファイルが空か判定する
function! Is_empty()
	return wordcount().bytes==0
endfunction

"g:cptargetの設定
function! Set_cptarget()
	let g:cptarget=expand("%:t")
endfunction

"g:cperroridの設定
function! Set_cperrorid()
	let g:cperrorid=win_getid() 
endfunction

"コンパイル結果の記録
function! CompileError_Check()
	if Is_empty()
		let g:cpresult=1
		silent execute "normal :q!\<CR>"
		let g:cperror_display=0
	else
		let g:cpresult=0
	endif
endfunction

"g++を走らせる
function! Compile_cpp()
	execute "normal :echo 'Trying to compile '.g:cptarget\<CR>"
	silent execute "normal :sp CompileError\<CR>"
	let g:cperror_display=1
	silent execute "normal :call Set_cperrorid()\<CR>"
	silent execute "normal gg\<S-v>Gd"
	silent execute "normal \<S-v>:!g++ -std=gnu++17 -o a -I . a.cpp\<CR>"
	execute "normal \<ESC>:call CompileError_Check()\<CR>"
endfunction

"コンパイル結果の報告
function! Compile_result_message()
	execute "normal :echo ''\<CR>"
	if g:cperror_display==0
		if g:cpresult==1
			execute "normal :echo g:cptarget.' was compiled successfully.'\<CR>"
		endif
	else
		if g:cpresult==0
			execute "normal :echo g:cptarget.' failed to compile.'\<CR>"
		endif
	endif
	silent execute "normal :call Go_mainspace()\<CR>"
endfunction

"コンパイルエラー表示を消す
function! Close_cperror()
	silent execute "normal :call win_gotoid(g:cperrorid)\<CR>"
	silent execute "normal :q!\<CR>"
	let g:cperror_display=0
	silent execute "normal :call Go_mainspace()\<CR>"
endfunction

"F5押したときの分岐
function! F5_junction_cpp()
	if g:cperror_display==1
		silent execute "normal :call Close_cperror()\<CR>"
	endif
	execute "normal :call Compile_cpp()\<CR>"
endfunction

nnoremap <F4> <ESC> :w<CR> :!xclip -selection c % <CR><CR>hh:echo expand("%:t") 'was clipped'<CR>
inoremap <F4> <ESC> :w<CR> :!xclip -selection c % <CR><CR>hh:echo expand("%:t") 'was clipped'<CR>
autocmd filetype cpp nnoremap <F5> :w<CR>:call Set_cptarget()<CR>:call F5_junction_cpp()<CR>:call Compile_result_message()<CR>
