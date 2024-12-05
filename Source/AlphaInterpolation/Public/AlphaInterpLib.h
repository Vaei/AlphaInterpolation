// Copyright (c) Jared Taylor. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AlphaInterp.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AlphaInterpLib.generated.h"

/**
 * Blueprint functions for working with FAlphaInterp
 */
UCLASS()
class ALPHAINTERPOLATION_API UAlphaInterpLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Interpolate a value by calling on tick
	 * @return Interpolated value
	 */
	UFUNCTION(BlueprintCallable, Category=Interpolation)
	static float AlphaInterpolateUpdate(UPARAM(ref)FAlphaInterp& AlphaInterp, float TargetValue, float DeltaTime)
	{
		return AlphaInterp.Interpolate(TargetValue, DeltaTime);
	}

	/**
	 * Add decay, which will be deducted from the current value over time
	 */
	UFUNCTION(BlueprintCallable, Category=Interpolation)
	static void AlphaInterpolateDecay(UPARAM(ref)FAlphaInterp& AlphaInterp, float DecayAmount)
	{
		AlphaInterp.Decay(DecayAmount);
	}

	/**
	 * Remove all decay
	 */
	UFUNCTION(BlueprintCallable, Category=Interpolation)
	static void AlphaInterpolateRemoveAllDecay(UPARAM(ref)FAlphaInterp& AlphaInterp)
	{
		AlphaInterp.RemoveAllDecay();
	}

	/**
	 * Initialize the interpolation
	 */
	UFUNCTION(BlueprintCallable, Category=Interpolation)
	static void AlphaInterpolateInitialize(UPARAM(ref)FAlphaInterp& AlphaInterp, float InitializeTo = 0.f)
	{
		AlphaInterp.Initialize(InitializeTo);
	}

	/**
	 * Finalize the interpolation
	 */
	UFUNCTION(BlueprintCallable, Category=Interpolation)
	static void AlphaInterpolateFinalize(UPARAM(ref)FAlphaInterp& AlphaInterp)
	{
		AlphaInterp.Finalize();
	}

	/**
	 * @return The current interpolated value
	 */
	UFUNCTION(BlueprintPure, Category=Interpolation)
	static float GetAlphaInterpolatedValue(const FAlphaInterp& AlphaInterp)
	{
		return AlphaInterp.GetInterpolatedValue();
	}

	/**
	 * @return The last target value
	 */
	UFUNCTION(BlueprintPure, Category=Interpolation)
	static float GetLastAlphaInterpolatedTargetValue(const FAlphaInterp& AlphaInterp)
	{
		return AlphaInterp.GetLastTargetValue();
	}

	/**
	 * @return True if the interpolation has completed
	 */
	UFUNCTION(BlueprintPure, Category=Interpolation)
	static bool HasAlphaInterpolateCompleted(const FAlphaInterp& AlphaInterp)
	{
		return AlphaInterp.HasCompleted();
	}

	/**
	 * Reset the interpolation
	 */
	UFUNCTION(BlueprintCallable, Category=Interpolation)
	static void AlphaInterpolateReset(UPARAM(ref)FAlphaInterp& AlphaInterp)
	{
		AlphaInterp.Reset();
	}

	/**
	 * @return True if the interpolation is active (currently in progress, not at the target value)
	 */
	UFUNCTION(BlueprintPure, Category=Interpolation)
	static bool IsAlphaInterpolateActive(const FAlphaInterp& AlphaInterp)
	{
		return AlphaInterp.IsActive();
	}

	/**
	 * @return True if the interpolation is interpolating in
	 */
	UFUNCTION(BlueprintPure, Category=Interpolation)
	static bool IsAlphaInterpolatingIn(const FAlphaInterp& AlphaInterp)
	{
		return AlphaInterp.State.IsInterpolatingIn();
	}

	/**
	 * @return True if the interpolation is interpolating out
	 */
	UFUNCTION(BlueprintPure, Category=Interpolation)
	static bool IsAlphaInterpolatingOut(const FAlphaInterp& AlphaInterp)
	{
		return AlphaInterp.State.IsInterpolatingOut();
	}

	/**
	 * @return True if the interpolation is paused
	 */
	UFUNCTION(BlueprintPure, Category=Interpolation)
	static bool IsAlphaInterpolatePaused(const FAlphaInterp& AlphaInterp)
	{
		return AlphaInterp.IsPaused();
	}

	/**
	 * Pause or resume the interpolation
	 */
	UFUNCTION(BlueprintCallable, Category=Interpolation)
	static void SetAlphaInterpolatePaused(UPARAM(ref)FAlphaInterp& AlphaInterp, bool bPaused)
	{
		AlphaInterp.SetPaused(bPaused);
	}
};
