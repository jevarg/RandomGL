
#ifndef _Cube_H_
# define _Cube_H_

# include <iostream>
# include "Geometry.hpp"
# include "ATransformation.hpp"
# include "Texture.hpp"

class Cube : public ATransformation
{
public:
    Cube();
    Cube(const Cube& c);
    Cube& operator=(const Cube& c);
    virtual ~Cube();
    
    void	build();
    bool	loadTexture(const std::string &path, bool smooth = false);
    void	draw(Shader *shader);
    void	destroy();
    
private:
    Geometry	*_geometry;
    Texture		*_texture;
};

#endif /* _Cube_H_ */
