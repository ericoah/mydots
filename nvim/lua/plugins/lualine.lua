-- Lualine
-- https://github.com/nvim-lualine/lualine.nvim
return {
	'nvim-lualine/lualine.nvim',
    	dependencies = { 'nvim-tree/nvim-web-devicons' },
--[[ Configure Lualine  ]]--
-- See themes in https://github.com/nvim-lualine/lualine.nvim/blob/master/THEMES.md
	config = function()
		require('lualine').setup({
			options = { 
	 			theme = 'dracula'
			}
		})
		end
}


