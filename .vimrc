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
"背景色を黒にする
autocmd ColorScheme * highlight Normal ctermbg=16 
"カラースキームの設定
colorscheme default
"テキストを折り返さない
set nowrap
"文字コードの設定
set encoding=utf-8
"バックアップファイルを作成しない
set nobackup
"画面端でのスクロールに余裕をもつ
set scrolloff=16
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
"マウス操作を有効にする
set mouse=a
"クリップボードと連携
set clipboard+=unnamed
"括弧補完
inoremap { {}<LEFT>
inoremap ( ()<LEFT>
inoremap [ []<LEFT>
inoremap " ""<LEFT>
inoremap ' ''<LEFT>
function! Check()
	if getline('.')[col('.')-2]=='{'
		return 1
	elseif getline('.')[col('.')-2]==':'
		return 1
	else
		return 0
	endif
endfunction
inoremap <expr><CR> Check() ? "<CR><ESC><S-o>" : "<CR>"
