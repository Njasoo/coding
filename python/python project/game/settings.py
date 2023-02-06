class Settings:
    def __init__(self):
        # setting of screen
        self.screen_width = 1200
        self.screen_height = 800
        self.bg_color = (230, 230, 230)
        # setting of ship
        self.ship_speed = 1.5
        self.ship_limit = 3
        # setting of bullet
        self.bullet_speed = 1.5
        self.bullet_width = 10
        self.bullet_height = 15
        self.bullet_color = (60, 60, 60)
        self.bullet_allow = 3
        # setting of alien
        self.alien_speed = 1.0
        self.fleet_drop_speed = 25
        self.fleet_direction = 1 # +1 means right, -1 means left
        # dynamic settings
        self.score_scale = 1.5
        self.speedup_scale = 1.1
        self.initialize_dynamic_settings()

    def initialize_dynamic_settings(self):
        self.ship_speed = 1.5
        self.bullet_speed = 3.0
        self.alien_speed = 1.0
        self.fleet_direction = 1
        self.alien_points = 50

    def increse_speed(self):
        self.ship_speed *= self.speedup_scale
        self.bullet_speed *= self.speedup_scale
        self.alien_speed *= self.speedup_scale
        self.alien_points = int(self.alien_points * self.score_scale)
