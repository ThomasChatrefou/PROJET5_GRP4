#pragma once
#include "FloorNode.h"

enum class ESplitOrientation
{
	ESO_Horizontal,
	ESO_Vertical
};

class Floor 
{
public:
	Floor();
	Floor(int32 GridSizeX, int32 GridSizeY, int32 NodeMinX, int32 NodeMinY, float SplitChanceFactor);

	~Floor();

	// Function called to split the floor
	void Partition();

	// Give a random binary value
	int32 CoinFlip();

	// Check if a node can be split based on some fixed and random constaints
	bool ShouldSplitNode(TSharedPtr<FloorNode> InNode, ESplitOrientation Orientation);

	// Try to split a node, return true if it is successful
	bool SplitAttempt(TSharedPtr<FloorNode> InNode);

	// Split a node Horizontally
	void SplitHorizontal(TSharedPtr<FloorNode> InA, TSharedPtr<FloorNode> InB, TSharedPtr<FloorNode> InC);
	
	// Split a node Vertically
	void SplitVertical(TSharedPtr<FloorNode> InA, TSharedPtr<FloorNode> InB, TSharedPtr<FloorNode> InC);

	// Draw helpers
	void DrawFloorNodes(class UWorld* World, FVector Offset, float UnitLength, float GridHeight, float Thickness);

	void DrawFloorNode(class UWorld* World, FCornerCoordinates coordinates, FVector Offset, float UnitLength, float GridHeight, float Thickness);

	// Get the partitioned floor grid
	FORCEINLINE TArray<TSharedPtr<FloorNode>> GetPartitionedFloor() const { return PartitionedFloor; }

private:
	// Hold the nodes during the spliting algorithm, it will end up empty
	TArray<TSharedPtr<FloorNode>> FloorNodeStack;

	// Final Room partition of nodes
	TArray<TSharedPtr<FloorNode>> PartitionedFloor;

	// Dimensions of the Room's grid
	int32 FloorGridSizeX;
	int32 FloorGridSizeY;

	// Minimal node size
	int32 RoomMinX;
	int32 RoomMinY;

	// Factor that allows us to control the chance of split on nodes
	float SplitChance;

};