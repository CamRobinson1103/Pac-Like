#include "PathfindBehavior.h"
#include "Maze.h"

void PathfindBehavior::update(Agent* owner, float deltaTime)
{
	//Don't update if disabled or no target
	if (!getEnabled() || !m_target)
		return;

	//Find the positions and tiles of the owner and target
	MathLibrary::Vector2 ownerPosition = owner->getWorldPosition();
	MathLibrary::Vector2 destinationPosition = findDestination(owner);
	Maze::Tile ownerTile = m_maze->getTile(ownerPosition);
	Maze::Tile destinationTile = m_maze->getTile(destinationPosition);

	//Update the path if needed
	if (m_needPath)
		updatePath(owner, destinationPosition);

	//Find the position and tile of the next node
	MathLibrary::Vector2 nextPosition = ownerPosition;
	if (!m_path.empty())
		nextPosition = m_path.front()->position;
	Maze::Tile nextTile = m_maze->getTile(nextPosition);

	//If owner is at the front node, go to the following node
	if (ownerTile.x == nextTile.x && ownerTile.y == nextTile.y) {
		if (!m_path.empty())
			m_path.pop_front();
		m_needPath = true;
	}

	//Find the direction
	MathLibrary::Vector2 direction = { 0.0f, 0.0f };
	if (!m_path.empty())
		direction = MathLibrary::Vector2::normalize(m_path.front()->position - ownerPosition);

	//Calculate the force
	MathLibrary::Vector2 desiredVelocity = direction * owner->getMaxSpeed();
	MathLibrary::Vector2 steeringForce = desiredVelocity - owner->getVelocity();

	//Apply the force
	owner->applyForce(steeringForce);
}

void PathfindBehavior::draw(Agent* owner)
{
	for (NodeGraph::Node* node : m_path)
	{
		NodeGraph::drawNode(node, m_color);
	}
}

void PathfindBehavior::updatePath(Agent* owner)
{
	updatePath(owner, m_target->getWorldPosition());
}

void PathfindBehavior::updatePath(Agent* owner, MathLibrary::Vector2 destination)
{
	NodeGraph::Node* ownerNode = m_maze->getTile(owner->getWorldPosition()).node;
	NodeGraph::Node* targetNode = m_maze->getTile(destination).node;
	m_path = NodeGraph::findPath(ownerNode, targetNode);
	if (!m_path.empty()) m_path.pop_front();
	m_needPath = false;
	//If Yakuza HD collection gets finished downloading (which is more than likely) I'd try it out for a miunute or two
	//Honestly I kinda like the gameplay for what little I'd play from Y1 and Y2, especially Y2. I can't explain why but I like how the game feels...arcade-y.
	//I think this started when I play Y3 (which I'm currently stil playing at the moment). Since the combat is an evolution of Y1 and Y2, I think it'll be a smoother transition to go back
	//unlink going from YK1 to YK2 to 3. THO! One issue I may come across in this Yakuza marathon I'm doin is Kenzan. For one, it is used, meaning it may not work, though I'm not as afraid of that notion because I have trust in the seller
	//THE REAL PROBLEM is gonna be WHEN I'll be getting Kenzan. It say it won't arrive here until May... a whole month and a week from now. Now this is subject to change,
	//especially since I just ordered it this morning, but as of right now it says May. Now on the plus side, after YS I'm going back to play Y1 and Y2 so I'll have more time til it gets here
	//But I don't think those games are particually long. They're at least shorter than their remakes, that's for sure.
	//If I don't have Kenzan before I finish Y2 I'll play another game, prolly DDS. The combination of Y3, Y1, Y2, and DDS is more than enough time for Kenzan to arrive.
	// I also had the thought of playing YK1 and YK2 again on NG+. I don't know if I will but I might. I already finished YK2 not too long ago and I don't know if I'll feel up to playing Y2's story
	//3x this year but we'll see. I can't wait to get to that grip of game in Y5, Ishin, and Y0. I already played Y0 (it's actually my first Yakuza game) and I already know it's fire,
	//and seeing Y5 and Ishin makes me more excited to play that era of Yakuza games. And it'll give me a greater appreciation of Y0 for it's refrences to older games and evolution of the gameplay.
	//Man I hate the notion people have about how "nobody cares about old games". It makes me mad because they don't care about keeping history. Imma keep it a mean bean machine,
	//I don't really care for remakes. I'd rather play the orginal games no matter how janky it is over a remake because for the most part
	//remake don't keep the essence of the original game. Since I'm currently playing the series, YK1 and YK2 is a PRIME example. In my opinion no remake should replace a game. Rather they should be just another version of that game.
	//A good example is the FF7 remake.

	//Ya know I just bought MGS1. I never played a MGS game before so I might have to check the series out ofter Yakuza. Actallu that's cap bc I played a little Metal Gear Rising, but I'm not sure if that counts. I also bought Xenogears. For the next few months imma try to get
	//as many games on the PS3 PSN as I can, or at least the ones I have any intrest in, even a little bit. For the most part I have the games I want but there are a few I mif=ght pick up.
	//DLC is also gonna be an issue. For the Tales game I have on PS3 (sans Symphonia bc it's a ps2 port) they all have DLC I don't have yet. Tho it's only costumes, so I don really care THAT much. But then again
	// one of my favorite things in Tales is the costumes. So now that I'm in the era of Tales that I have to pay for HALF of the costumes in the game
	//it's tempting me to but them. BUT I MUST STAY STRONG!...tho if the funds are lookin okay I might buy them if I have time.
}
