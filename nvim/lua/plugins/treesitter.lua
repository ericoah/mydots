-- Treesitter
-- https://github.com/nvim-treesitter/nvim-treesitter/wiki/Installation

return {
	"nvim-treesitter/nvim-treesitter", 
	build = ":TSUpdate",
--[[ Configure Treesitter ]]--
	config = function()
		local config = require("nvim-treesitter.configs")
		config.setup({
		ensure_installed = { "c", "lua", "python", "html", "markdown", "r" },
          	sync_install = false,
          	highlight = { enable = true },
          	indent = { enable = true },
        	})
end
}
