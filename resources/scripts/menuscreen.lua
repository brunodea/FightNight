FONT_SIZE_DEFAULT = 18
FONT_DEFAULT = "../resources/fonts/diablo_2.ttf" 

function MenuOpt(self)
    if not self.text then
        self.text = "No Text"
    end

    if not self.font then
        self.font = FONT_DEFAULT
    end

    if not self.fontsize then
        self.fontsize = FONT_SIZE_DEFAULT
    elseif self.fontsize <= 0 then
        ReportError("Invalid font size value.")
    end    
    
    return self
end

title_screen = {
    size = 4,
    MenuOpt{
        text = "PLAY",
--        font = "../resources/fonts/crackman.ttf",
        fontsize = 18
    },
    MenuOpt{
        text = "MULTIPLAYER",
--        font = "../resources/fonts/Starcraft.ttf",
        fontsize = 18
    },
    MenuOpt{
        text = "OPTIONS",
--        font = "../resources/fonts/Starcraft.ttf",
        fontsize = 18
    },
    MenuOpt{
        text = "EXIT",
--        font = "../resources/fonts/Starcraft.ttf",
        fontsize = 18
    }
}

