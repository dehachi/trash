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
"シンタックスハイライトを有効にする
syntax on
"tabを4文字分にする
set tabstop=4
"インデントを4文字分にする
set shiftwidth=4
"c言語に特化したオートインデント
set cindent
"左右のカーソル移動で行を跨いで移動
set whichwrap=b,s,h,l,<,>,[,],~
"背景色
autocmd ColorScheme * highlight Normal ctermbg=16
"補完色
autocmd ColorScheme * highlight Pmenu ctermbg=237 ctermfg=255
autocmd ColorScheme * highlight PmenuSel ctermbg=1, ctermfg=255
"カラースキームの設定
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
"クリップボードと連携
set clipboard+=unnamed
"swapファイルを無効にする
set noswapfile
"ステータスライン
set statusline=%f%r%h%w%m%=%{&fileformat}\ %{&fileencoding}\ [%l,%c]
set laststatus=2
