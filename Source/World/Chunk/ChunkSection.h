#ifndef CHUNKSECTION_H_INCLUDED
#define CHUNKSECTION_H_INCLUDED

#include <array>
#include <SFML/Graphics.hpp>

#include "../WorldConstants.h"
#include "../Block/ChunkBlock.h"
#include "ChunkMesh.h"
#include "IChunk.h"

class World;

class ChunkSection : public IChunk
{
    friend class Chunk;
    public:
        ChunkSection(const sf::Vector3i& position, World& world);

        void setBlock       (int x, int y, int z, ChunkBlock block) override;
        ChunkBlock getBlock (int x, int y, int z) const override;

        const sf::Vector3i getLocation() const;

        ///@TODO make private


    private:
        sf::Vector3i toWorldPosition (int x, int y, int z) const noexcept;

        static bool outOfBounds (int value);
        static int  getIndex    (int x, int y, int z);


        std::array<ChunkBlock, CHUNK_VOLUME>    m_blocks;
        ChunkMesh                               m_mesh;
        sf::Vector3i                            m_location;

        World* m_pWorld;
};

#endif // CHUNKSECTION_H_INCLUDED
