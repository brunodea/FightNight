FONT_SIZE_DEFAULT = 18
FONT_DEFAULT = "../resources/fonts/crackman.ttf" 

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
    
    if not self.clickable then
        self.clickable = true
    end

    if not self.rect then
        self.rect = {}
    end

    if not self.rect.x then
        self.rect.x = 0
    end

    if not self.rect.y then
        self.rect.y = 0
    end

    if not self.rect.width then
        self.rect.width = 10
    end
    
    if not self.rect.height then
        self.rect.height = 10
    end

    return self
end

title_screen = {
    size = 4,
    position = {
        x = 340,
        y = 270,
    },
    MenuOpt {
        text = "PLAY",
--        font = "../resources/fonts/crackman.ttf",
        fontsize = 18,
        rect = {
            x = 25,
            width = 50,
            height = 20,
        }
    },
    MenuOpt{
        text = "MULTIPLAYER",
--        font = "../resources/fonts/Starcraft.ttf",
        fontsize = 18,
        rect = {
            x = -15,
            width = 140,
            height = 20,
        }
    },
    MenuOpt{
        text = "OPTIONS",
--        font = "../resources/fonts/Starcraft.ttf",
        fontsize = 18,
        rect = {
            x = 10,
            width = 90,
            height = 20,
        }
    },
    MenuOpt{
        text = "EXIT",
--        font = "../resources/fonts/Starcraft.ttf",
        fontsize = 18,
        rect = {
            x = 25,
            width = 50,
            height = 20,
        }
    },
}



